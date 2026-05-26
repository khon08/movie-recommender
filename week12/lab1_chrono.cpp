#include <iostream>
#include <chrono>

using namespace std::chrono;
using clk = high_resolution_clock;

long long sumLoop(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    return sum;
}

long long sumFormula(int n) {
    return (long long)n * (n + 1) / 2;
}

int main() {
    const int N = 100000000;

    auto s1 = clk::now();
    long long r1 = sumLoop(N);
    auto t1 = duration_cast<microseconds>(clk::now() - s1);

    auto s2 = clk::now();
    long long r2 = sumFormula(N);
    auto t2 = duration_cast<nanoseconds>(clk::now() - s2);

    std::cout << "=== 실습 1: 알고리즘 속도 비교 ===" << std::endl;
    std::cout << "반복문 결과: " << r1 << std::endl;
    std::cout << "반복문 시간: " << t1.count() << " us" << std::endl;
    std::cout << "수식 결과:   " << r2 << std::endl;
    std::cout << "수식 시간:   " << t2.count() << " ns" << std::endl;

    return 0;
}