#include "Recommender.h"
#include <iostream>
#include <algorithm>

// 생성자
Recommender::Recommender(const MovieManager& movieMgr,
                         const UserManager& userMgr,
                         const RatingManager& ratingMgr)
    : movieMgr(movieMgr), userMgr(userMgr), ratingMgr(ratingMgr) {}

// 유사 사용자 찾기 (상위 K명)
std::vector<std::pair<int, int>> Recommender::findSimilarUsers(int targetUserId, int k) const {
    std::vector<Rating> myRatings = ratingMgr.findByUser(targetUserId);
    std::vector<std::pair<int, int>> similarities;

    for (int otherId : ratingMgr.getAllUserIds()) {
        if (otherId == targetUserId) continue;

        std::vector<Rating> otherRatings = ratingMgr.findByUser(otherId);
        int sim = SimilarityCalculator::calculate(myRatings, otherRatings);

        if (sim > -100) {
            similarities.push_back({otherId, sim});
        }
    }

    // 유사도 내림차순 정렬
    std::sort(similarities.begin(), similarities.end(),
        [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            return a.second > b.second;
        });

    // 상위 K명만 반환
    if ((int)similarities.size() > k) {
        similarities.resize(k);
    }

    return similarities;
}

// 추천 영화 목록 반환
std::vector<int> Recommender::recommend(int targetUserId, int n) const {
    // 내가 본 영화 목록
    std::vector<Rating> myRatings = ratingMgr.findByUser(targetUserId);
    std::vector<int> myMovieIds;
    for (const Rating& r : myRatings) {
        myMovieIds.push_back(r.getMovieId());
    }

    // 유사 사용자 찾기 (상위 2명)
    std::vector<std::pair<int, int>> similarUsers = findSimilarUsers(targetUserId, 2);

    // 후보 영화 수집
    std::vector<std::pair<int, int>> candidates;

    for (const auto& simUser : similarUsers) {
        int otherId = simUser.first;

        std::vector<Rating> otherRatings = ratingMgr.findByUser(otherId);

        for (const Rating& r : otherRatings) {
            int movieId = r.getMovieId();

            // 내가 이미 본 영화는 제외
            bool alreadySeen = false;
            for (int myMovieId : myMovieIds) {
                if (myMovieId == movieId) {
                    alreadySeen = true;
                    break;
                }
            }
            if (alreadySeen) continue;

            // 높은 평점만 추천 (4점 이상)
            if (r.getScore() >= 4) {
                candidates.push_back({movieId, r.getScore()});
            }
        }
    }

    // 점수 내림차순 정렬
    std::sort(candidates.begin(), candidates.end(),
        [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            return a.second > b.second;
        });

    // 중복 제거 후 상위 N개 반환
    std::vector<int> result;
    for (const auto& c : candidates) {
        bool duplicate = false;
        for (int id : result) {
            if (id == c.first) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            result.push_back(c.first);
        }
        if ((int)result.size() >= n) break;
    }

    return result;
}

// 추천 결과 출력
void Recommender::printRecommendations(int targetUserId, int n) const {
    std::cout << "=== User " << targetUserId << " 추천 영화 ===\n";

    std::vector<Rating> myRatings = ratingMgr.findByUser(targetUserId);
    if (myRatings.empty()) {
        std::cout << "평점 데이터가 없습니다.\n";
        return;
    }

    std::vector<int> recommendations = recommend(targetUserId, n);

    if (recommendations.empty()) {
        std::cout << "추천할 영화가 없습니다.\n";
        return;
    }

    int rank = 1;
    for (int movieId : recommendations) {
        Movie* movie = movieMgr.findById(movieId);
        std::string title = movie ? movie->getTitle() : "Unknown";
        std::cout << rank++ << ". " << title << " (ID: " << movieId << ")\n";
    }
}