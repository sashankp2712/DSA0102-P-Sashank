#include <iomanip>
#include <iostream>

int main() {
    constexpr long long JOURNEYS = 3000000;
    constexpr long long FARE_PAISE = 3000; // ₹30 per journey

    long long integerTotalPaise = 0;
    double doubleTotalRupees = 0.0;

    for (long long i = 0; i < JOURNEYS; ++i) {
        integerTotalPaise += FARE_PAISE;
        doubleTotalRupees += 30.0;
    }

    std::cout << "Journeys: " << JOURNEYS << '\n';
    std::cout << "Integer total: " << integerTotalPaise << " paise\n";
    std::cout << "Integer total: Rs " << integerTotalPaise / 100 << '\n';
    std::cout << std::setprecision(17)
              << "Double total: Rs " << doubleTotalRupees << '\n';
    std::cout << "Expected maximum example: Rs 90000000\n";
    return 0;
}
