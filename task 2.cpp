#include <iostream>

enum class Zone { Inner, Middle, Outer };

constexpr long long MIN_BALANCE_PAISE = 5000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};

int main() {
    std::cout << "Minimum balance: " << MIN_BALANCE_PAISE << " paise\n";
    std::cout << "Peak surcharge: " << PEAK_SURCHARGE_PERCENT << "%\n";
    for (long long fare : BASE_PAISE) {
        std::cout << "Base fare: " << fare << " paise\n";
    }
    Zone zone = Zone::Inner;
    (void)zone;
    return 0;
}
