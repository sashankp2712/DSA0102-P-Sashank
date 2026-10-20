#include <climits>
#include <iomanip>
#include <iostream>

int main() {
    std::cout << "sizeof(bool) = " << sizeof(bool) << '\n';
    std::cout << "sizeof(char) = " << sizeof(char) << '\n';
    std::cout << "sizeof(int) = " << sizeof(int) << '\n';
    std::cout << "sizeof(long long) = " << sizeof(long long) << '\n';
    std::cout << "sizeof(float) = " << sizeof(float) << '\n';
    std::cout << "sizeof(double) = " << sizeof(double) << '\n';
    std::cout << "INT_MIN = " << INT_MIN << ", INT_MAX = " << INT_MAX << '\n';
    std::cout << "LLONG_MIN = " << LLONG_MIN << ", LLONG_MAX = " << LLONG_MAX << '\n';

    double rupees = 0.0;
    long long paise = 0;
    for (int i = 0; i < 3000000; ++i) {
        rupees += 0.1;
        paise += 10;
    }
    std::cout << std::setprecision(17)
              << "Double total after adding 0.1 three million times: "
              << rupees << '\n';
    std::cout << "Integer total: " << paise << " paise = "
              << paise / 100.0 << " rupees\n";
    return 0;
}
