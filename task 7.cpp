#include <iostream>

constexpr long long MIN_BALANCE_PAISE = 5000;

bool proceduralCanTravel(long long balance, long long farePaise) {
    return farePaise >= 0 && balance - farePaise >= MIN_BALANCE_PAISE;
}

bool proceduralDeduct(long long& balance, long long farePaise) {
    if (!proceduralCanTravel(balance, farePaise)) {
        return false;
    }
    balance -= farePaise;
    return true;
}

class SmartCard {
private:
    long long balancePaise_;

public:
    explicit SmartCard(long long initialBalancePaise)
        : balancePaise_(initialBalancePaise) {}

    long long balance() const {
        return balancePaise_;
    }

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 &&
               balancePaise_ - farePaise >= MIN_BALANCE_PAISE;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) {
            return false;
        }
        balancePaise_ -= farePaise;
        return true;
    }
};

int main() {
    long long proceduralBalance = 10000;
    std::cout << "Procedural accepted: "
              << std::boolalpha << proceduralDeduct(proceduralBalance, 3000)
              << ", balance=" << proceduralBalance << '\n';

    SmartCard card(10000);
    std::cout << "OOP accepted: " << card.deduct(3000)
              << ", balance=" << card.balance() << '\n';
    std::cout << "Large fare accepted: " << card.deduct(3000)
              << ", balance=" << card.balance() << '\n';
    return 0;
}
