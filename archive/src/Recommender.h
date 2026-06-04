#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include <vector>
#include <string>
#include "Rating.h"
#include "Movie.h"
#include "User.h"
#include "RatingManager.h"
#include "MovieManager.h"
#include "UserManager.h"
#include "SimilarityCalculator.h"

class Recommender {
private:
    // 세 Manager를 참조로 보관
    const MovieManager& movieMgr;
    const UserManager& userMgr;
    const RatingManager& ratingMgr;

public:
    // 생성자
    Recommender(const MovieManager& movieMgr,
                const UserManager& userMgr,
                const RatingManager& ratingMgr);

    // 유사 사용자 찾기 (상위 K명)
    // 반환: <userId, 유사도> 쌍의 벡터
    std::vector<std::pair<int, int>> findSimilarUsers(int targetUserId, int k) const;

    // 추천 영화 목록 반환 (상위 N개)
    // 반환: movieId 벡터
    std::vector<int> recommend(int targetUserId, int n = 5) const;

    // 추천 결과 출력
    void printRecommendations(int targetUserId, int n = 5) const;
};

#endif