#include "Recommender.h"
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

int Recommender::Similaritycalculate(const vector<Rating>& ratingsA,
                                      const vector<Rating>& ratingsB) {
    int common = 0;
    int diff = 0;
    for (const auto& a : ratingsA) {
        for (const auto& b : ratingsB) {
            if (a.getMovieId() == b.getMovieId()) {
                common++;
                diff += abs((int)a.getScore() - (int)b.getScore());
            }
        }
    }
    if (common == 0) return -100;
    return common * 10 - diff;
}

vector<int> Recommender::recommend(int userId, int K, int N) {
    // 1단계: 내 평점 가져오기
    vector<Rating> myRatings = ratingManager.getByUser(userId);
    if (myRatings.empty()) return {};

    // 2단계: 모든 사용자와 유사도 계산
    vector<pair<int,int>> similarities;
    vector<int> allUsers = ratingManager.getAllUserIds();
    for (int uid : allUsers) {
        if (uid == userId) continue;
        vector<Rating> otherRatings = ratingManager.getByUser(uid);
        int sim = Similaritycalculate(myRatings, otherRatings);
        similarities.push_back({uid, sim});
    }

    // 3단계: 유사도 상위 K명 선택
    sort(similarities.begin(), similarities.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second > b.second;
         });
    int k = min(K, (int)similarities.size());

    // 4단계: 내가 본 영화 set
    set<int> myMovieIds;
    for (const auto& r : myRatings)
        myMovieIds.insert(r.getMovieId());

    // 5단계: 후보 영화 점수 누적
    map<int,int> movieScores;
    for (int i = 0; i < k; i++) {
        int uid = similarities[i].first;
        vector<Rating> otherRatings = ratingManager.getByUser(uid);
        for (const auto& r : otherRatings) {
            if (myMovieIds.find(r.getMovieId()) == myMovieIds.end()) {
                movieScores[r.getMovieId()] += (int)r.getScore();
            }
        }
    }

    // 정렬 후 상위 N개 반환
    vector<pair<int,int>> sorted(movieScores.begin(), movieScores.end());
    sort(sorted.begin(), sorted.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second > b.second;
         });

    vector<int> result;
    int n = min(N, (int)sorted.size());
    for (int i = 0; i < n; i++)
        result.push_back(sorted[i].first);
    return result;
}
