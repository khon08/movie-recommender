#include <iostream>
#include <vector>
#include "Rating.h"
#include "RatingManager.h"
#include "MovieManager.h"
#include "UserManager.h"
#include "SimilarityCalculator.h"

int main() {
    // 모든 Manager 생성 및 CSV 로드
    MovieManager movieMgr;
    UserManager userMgr;
    RatingManager ratingMgr;

    movieMgr.loadFromFile("../data/movies.csv");
    userMgr.loadFromFile("../data/users.csv");
    ratingMgr.loadFromFile("../data/ratings.csv");

    // 영화 목록 출력
    std::cout << "=== 영화 목록 ===\n";
    movieMgr.printAll();
    std::cout << "\n";

    // 유저 목록 출력
    std::cout << "=== 유저 목록 ===\n";
    userMgr.printAll();
    std::cout << "\n";

    // 평점 목록 출력
    std::cout << "=== 평점 목록 ===\n";
    ratingMgr.printAll();
    std::cout << "\n";

    // User 1과 다른 모든 유저의 유사도 계산
    int targetUserId = 1;
    std::vector<Rating> myRatings = ratingMgr.findByUser(targetUserId);

    std::cout << "=== 유사도 계산 (User " << targetUserId << " 기준) ===\n";

    int bestUser = -1;
    int bestSim = -101;

    for (int otherId : ratingMgr.getAllUserIds()) {
        if (otherId == targetUserId) continue;

        std::vector<Rating> otherRatings = ratingMgr.findByUser(otherId);
        int sim = SimilarityCalculator::calculate(myRatings, otherRatings);

        // 유저 이름 찾기
        User* user = userMgr.findById(otherId);
        std::string name = user ? user->getName() : "Unknown";

        std::cout << "User " << targetUserId
                  << " <-> " << name
                  << " : " << sim << "\n";

        if (sim > bestSim) {
            bestSim = sim;
            bestUser = otherId;
        }
    }

    User* best = userMgr.findById(bestUser);
    std::string bestName = best ? best->getName() : "Unknown";

    std::cout << "\n-> User 1과 가장 비슷한 사람: "
              << bestName
              << " (유사도 " << bestSim << ")\n";

    return 0;
}