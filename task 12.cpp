#include <array>
#include <cstddef>
#include <iostream>

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };
constexpr std::array<long long, 4> BASE_PAISE{1000, 2000, 3000, 6000};
constexpr int PEAK_PERCENT = 20;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr long long MIN_BALANCE_PAISE = 5000;

long long calculateFare(Zone zone, bool peak, bool weekend) {
    const int rawIndex = static_cast<int>(zone);
    if (rawIndex < 0 || rawIndex >= static_cast<int>(BASE_PAISE.size())) {
        return -1;
    }

    const auto index = static_cast<std::size_t>(rawIndex);
    const long long base = BASE_PAISE[index];

    // Weekend discount does not combine with the peak surcharge.
    if (weekend) {
        return base - base * WEEKEND_DISCOUNT_PERCENT / 100;
    }
    if (peak) {
        return base + base * PEAK_PERCENT / 100;
    }
    return base;
}

class Pass {
private:
    bool active_;
    Zone firstZone_;
    Zone secondZone_;

public:
    Pass(bool active, Zone firstZone, Zone secondZone)
        : active_(active), firstZone_(firstZone), secondZone_(secondZone) {}

    bool covers(Zone zone) const {
        return active_ && (zone == firstZone_ || zone == secondZone_);
    }
};

class SmartCard {
private:
    long long balancePaise_;

public:
    explicit SmartCard(long long initialBalancePaise)
        : balancePaise_(initialBalancePaise) {}

    long long balance() const { return balancePaise_; }

    bool canPay(long long farePaise) const {
        return farePaise >= 0 &&
               balancePaise_ - farePaise >= MIN_BALANCE_PAISE;
    }

    bool pay(long long farePaise) {
        if (!canPay(farePaise)) return false;
        balancePaise_ -= farePaise;
        return true;
    }
};

int main() {
    std::cout << "Airport off-peak: "
              << calculateFare(Zone::Airport, false, false) << " paise\n";
    std::cout << "Airport weekday peak: "
              << calculateFare(Zone::Airport, true, false) << " paise\n";
    std::cout << "Airport weekend: "
              << calculateFare(Zone::Airport, true, true) << " paise\n";

    Pass monthlyPass(true, Zone::Inner, Zone::Airport);
    std::cout << "Pass covers Airport: " << std::boolalpha
              << monthlyPass.covers(Zone::Airport) << '\n';

    SmartCard card(10000);
    const Zone tripZone = Zone::Airport;
    if (monthlyPass.covers(tripZone)) {
        std::cout << "Pass journey: no fare deduction. Balance remains "
                  << card.balance() << " paise\n";
    } else {
        const long long farePaise = calculateFare(tripZone, false, false);
        if (card.pay(farePaise)) {
            std::cout << "Paid journey. Balance: " << card.balance() << " paise\n";
        } else {
            std::cout << "Journey denied. Balance unchanged.\n";
        }
    }
    return 0;
}
