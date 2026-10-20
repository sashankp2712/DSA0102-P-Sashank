#include <iostream>
#include <string>

struct ProceduralCard {
    long long balancePaise;
};

bool proceduralCanTravel(long long balancePaise, long long farePaise) {
    constexpr long long MIN_BALANCE_PAISE = 5000;
    return farePaise >= 0 && balancePaise - farePaise >= MIN_BALANCE_PAISE;
}

int main() {
    ProceduralCard card{10000};
    const long long farePaise = 3000;

    if (proceduralCanTravel(card.balancePaise, farePaise)) {
        card.balancePaise -= farePaise;
        std::cout << "Accepted. Remaining balance: " << card.balancePaise
                  << " paise\n";
    } else {
        std::cout << "Denied. Balance unchanged: " << card.balancePaise
                  << " paise\n";
    }
    return 0;
}
