#include <iostream>
#include <vector>
#include "Rating.h"
#include "SimilarityCalculator.h"

int main() {
    std::vector<Rating> user1 = {
        Rating(1, 101, 5),
        Rating(1, 102, 4),
        Rating(1, 103, 3)
    };

    std::vector<Rating> user2 = {
        Rating(2, 101, 5),
        Rating(2, 102, 5),
        Rating(2, 104, 4)
    };

    int sim = SimilarityCalculator::calculate(user1, user2);

    std::cout << "유사도 결과: " << sim << "\n";
    std::cout << "기대값: 19, 실제값: " << sim << "\n";

    return 0;
}