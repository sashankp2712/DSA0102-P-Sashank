#include <chrono>
#include <iostream>

inline int addInline(int a, int b) {
    return a + b;
}

int addNormal(int a, int b) {
    return a + b;
}

int main() {
    volatile long long sum = 0;
    constexpr int N = 10000000;

    const auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < N; ++i) {
        sum += addInline(i, 1);
    }
    const auto middle = std::chrono::steady_clock::now();

    for (int i = 0; i < N; ++i) {
        sum += addNormal(i, 1);
    }
    const auto finish = std::chrono::steady_clock::now();

    const auto inlineNs =
        std::chrono::duration_cast<std::chrono::nanoseconds>(middle - start).count();
    const auto normalNs =
        std::chrono::duration_cast<std::chrono::nanoseconds>(finish - middle).count();

    std::cout << "sum=" << sum << '\n';
    std::cout << "inline ns=" << inlineNs << '\n';
    std::cout << "normal ns=" << normalNs << '\n';
    return 0;
}
