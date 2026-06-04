#include "SimilarityCalculator.h"
#include <cstdlib>

/**
 * 두 사용자 간의 유사도를 계산한다.
 *
 * 유사도 공식:
 *   similarity = (공통 영화 수 × 10) - (평점 차이의 합)
 *
 * 설계 결정:
 *   - 값이 클수록 더 비슷한 취향
 *   - 공통 영화 수에 10을 곱하는 이유:
 *     공통 영화의 "있음"이 "평점 약간 차이"보다 중요하기 때문
 *   - 공통 영화가 0개이면 -100 반환 (비교 불가)
 *
 * 엣지 케이스:
 *   - 공통 영화 0개 → -100 반환
 *   - 평점 차이가 0 → 완전히 같은 취향
 *   - 평점 차이가 최대 → 취향이 정반대
 *
 * 예시:
 *   User1: 인터스텔라(5), 기생충(4)
 *   User2: 인터스텔라(5), 기생충(5)
 *   공통 영화: 2개, 평점 차이: 0+1 = 1
 *   유사도: 2×10 - 1 = 19
 */
int SimilarityCalculator::calculate(
    const std::vector<Rating>& user1,
    const std::vector<Rating>& user2)
{
    int commonCount = 0;   // 공통으로 본 영화 수
    int scoreDiffSum = 0;  // 평점 차이의 합

    // 이중 반복문: user1의 모든 평점 x user2의 모든 평점
    for (const Rating& r1 : user1) {
        for (const Rating& r2 : user2) {
            if (r1.getMovieId() == r2.getMovieId()) {
                commonCount++;
                scoreDiffSum += std::abs(r1.getScore() - r2.getScore());
            }
        }
    }

    // 엣지 케이스: 공통 영화가 없으면 비교 불가
    if (commonCount == 0) {
        return -100;
    }

    // 유사도 공식: (공통 영화 수 × 10) - (평점 차이의 합)
    return commonCount * 10 - scoreDiffSum;
}