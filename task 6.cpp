#include <iomanip>
#include <iostream>

enum class Zone { Inner, Middle, Outer };
constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long fare(Zone z, bool peak) {
    long long base = 0;
    switch (z) {
        case Zone::Inner:  base = BASE_PAISE[0]; break;
        case Zone::Middle: base = BASE_PAISE[1]; break;
        case Zone::Outer:  base = BASE_PAISE[2]; break;
        default: return -1;
    }
    if (peak) {
        base += base * PEAK_SURCHARGE_PERCENT / 100;
    }
    return base;
}

bool canTravel(long long balance, long long farePaise) {
    return farePaise >= 0 && balance - farePaise >= MIN_BALANCE_PAISE;
}

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

int main() {
    long long balance = 10000;
    struct Trip { Zone zone; bool peak; };
    const Trip trips[] = {
        {Zone::Inner, false},
        {Zone::Outer, true},
        {Zone::Middle, false}
    };

    for (const Trip& trip : trips) {
        const long long f = fare(trip.zone, trip.peak);
        if (canTravel(balance, f)) {
            balance -= f;
            std::cout << "Fare Rs " << f / 100 << '.' << std::setw(2)
                      << std::setfill('0') << f % 100 << std::setfill(' ');
        } else {
            std::cout << "Denied (low balance)";
        }
        std::cout << " balance Rs " << balance / 100 << '\n';
    }

    std::cout << "08:00 peak = " << std::boolalpha << isPeakHour(8) << '\n';
    std::cout << "10:00 peak = " << isPeakHour(10) << '\n';
    std::cout << "17:00 peak = " << isPeakHour(17) << '\n';
    std::cout << "20:00 peak = " << isPeakHour(20) << '\n';
    return 0;
}
