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

    std::vector<Rating>* user2Ptr = nullptr; // ← 버그: 초기화 안 함!

    int sim = SimilarityCalculator::calculate(user1, *user2Ptr);

    std::cout << "유사도 결과: " << sim << "\n";

    return 0;
}