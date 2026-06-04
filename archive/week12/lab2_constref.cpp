#include <iostream>
#include <chrono>
#include <string>
#include <vector>

using namespace std::chrono;
using clk = high_resolution_clock;

struct BigData {
    std::string text;
    std::vector<int> nums;
};

void processCopy(BigData d) {
    (void)d.nums[0];
}

void processRef(const BigData& d) {
    (void)d.nums[0];
}

int main() {
    BigData data;
    data.text = std::string(10000, 'a');
    data.nums = std::vector<int>(10000, 42);

    const int N = 100000;

    auto s1 = clk::now();
    for (int i = 0; i < N; i++) processCopy(data);
    auto t1 = duration_cast<milliseconds>(clk::now() - s1);

    auto s2 = clk::now();
    for (int i = 0; i < N; i++) processRef(data);
    auto t2 = duration_cast<milliseconds>(clk::now() - s2);

    std::cout << "=== 실습 2: const& 효과 측정 ===" << std::endl;
    std::cout << "값 전달 (복사):  " << t1.count() << " ms" << std::endl;
    std::cout << "const& 전달:    " << t2.count() << " ms" << std::endl;

    return 0;
}