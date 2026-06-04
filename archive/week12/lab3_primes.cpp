#include <iostream>
#include <chrono>

using namespace std::chrono;
using clk = high_resolution_clock;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; (long long)i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main() {
    const int N = 1000000;

    auto s = clk::now();
    int count = 0;
    for (int i = 2; i <= N; i++)
        if (isPrime(i)) count++;
    auto t = duration_cast<milliseconds>(clk::now() - s);

    std::cout << "=== 실습 3: C++ 소수 세기 ===" << std::endl;
    std::cout << "소수 개수: " << count << std::endl;
    std::cout << "실행 시간: " << t.count() << " ms" << std::endl;

    return 0;
}