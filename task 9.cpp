#include <array>
#include <iostream>
#include <string>

enum class Zone { Inner, Middle, Outer };
constexpr std::array<long long, 3> BASE_PAISE{1000, 2000, 3000};
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    const int index = static_cast<int>(zone);
    if (index < 0 || index >= static_cast<int>(BASE_PAISE.size()) ||
        hour < 0 || hour > 23) {
        return -1;
    }
    long long amount = BASE_PAISE[static_cast<std::size_t>(index)];
    if (isPeakHour(hour)) {
        amount += amount * 20 / 100;
    }
    return amount;
}

struct TestCase {
    std::string name;
    Zone zone;
    int hour;
    long long expectedPaise;
};

int main() {
    const TestCase tests[] = {
        {"Inner off-peak", Zone::Inner, 12, 1000},
        {"Middle off-peak", Zone::Middle, 14, 2000},
        {"Outer off-peak", Zone::Outer, 12, 3000},
        {"Inner at 08:00", Zone::Inner, 8, 1200},
        {"Outer at 17:00", Zone::Outer, 17, 3600},
        {"Inner at 10:00", Zone::Inner, 10, 1000},
        {"Inner at 20:00", Zone::Inner, 20, 1000}
    };

    int failures = 0;
    for (const auto& test : tests) {
        const long long actual = calculateFare(test.zone, test.hour);
        const bool pass = actual == test.expectedPaise;
        std::cout << (pass ? "PASS " : "FAIL ") << test.name
                  << ": expected=" << test.expectedPaise
                  << ", actual=" << actual << " paise\n";
        if (!pass) {
            ++failures;
        }
    }

    const long long exactReserveBalance = 6200;
    const long long peakInnerFare = calculateFare(Zone::Inner, 8);
    const bool exactReserveAccepted =
        exactReserveBalance - peakInnerFare >= MIN_BALANCE_PAISE;
    std::cout << "Exactly Rs 50 remains: "
              << (exactReserveAccepted ? "PASS" : "FAIL") << '\n';
    std::cout << "Failures: " << failures << '\n';
    return failures == 0 ? 0 : 1;
}
