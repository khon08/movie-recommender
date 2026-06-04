#include <iostream>
#include <vector>
#include "Rating.h"
#include "RatingManager.h"
#include "MovieManager.h"
#include "UserManager.h"
#include "SimilarityCalculator.h"
#include "Recommender.h"

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

    // 유사도 계산
    std::cout << "=== 유사도 계산 (User 1 기준) ===\n";
    std::vector<Rating> myRatings = ratingMgr.findByUser(1);
    for (int otherId : ratingMgr.getAllUserIds()) {
        if (otherId == 1) continue;
        std::vector<Rating> otherRatings = ratingMgr.findByUser(otherId);
        int sim = SimilarityCalculator::calculate(myRatings, otherRatings);
        User* user = userMgr.findById(otherId);
        std::string name = user ? user->getName() : "Unknown";
        std::cout << "User 1 <-> " << name << " : " << sim << "\n";
    }
    std::cout << "\n";

    // Recommender 생성 및 추천
    Recommender recommender(movieMgr, userMgr, ratingMgr);
    recommender.printRecommendations(1, 5);

    return 0;
}