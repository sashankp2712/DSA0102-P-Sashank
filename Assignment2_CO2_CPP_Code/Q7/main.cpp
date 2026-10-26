#include <array>
#include <cstddef>
#include <iostream>

template <std::size_t K>
class CircularHistory {
private:
    std::array<int, K> data_{};
    std::size_t next_ = 0;
    std::size_t count_ = 0;

public:
    void add(int value) {
        data_[next_] = value;
        next_ = (next_ + 1) % K;
        if (count_ < K) {
            ++count_;
        }
    }

    void print() const {
        const std::size_t oldest = (next_ + K - count_) % K;
        for (std::size_t i = 0; i < count_; ++i) {
            std::cout << data_[(oldest + i) % K] << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    CircularHistory<10> history;
    for (int i = 1; i <= 12; ++i) {
        history.add(i);
    }
    history.print(); // Expected: 3 4 5 6 7 8 9 10 11 12
    return 0;
}
