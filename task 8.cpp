#include <iomanip>
#include <iostream>
#include <limits>

int main() {
    int hour = -1;
    while (true) {
        std::cout << "Enter hour (0-23): ";
        if (std::cin >> hour) {
            if (hour >= 0 && hour <= 23) {
                break;
            }
            std::cout << "Hour out of range. Try again.\n";
        } else {
            if (std::cin.eof()) {
                std::cout << "\nInput ended.\n";
                return 1;
            }
            std::cout << "Invalid number. Try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    const long long farePaise = 1234;
    std::cout << "Accepted hour: " << hour << '\n';
    std::cout << "Fare Rs " << farePaise / 100 << '.'
              << std::setw(2) << std::setfill('0') << farePaise % 100
              << std::setfill(' ') << '\n';
    return 0;
}
