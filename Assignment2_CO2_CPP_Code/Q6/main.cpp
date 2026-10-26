#include <cstdlib>
#include <iostream>

class Time {
    int h;
    int m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b) {
    const int first = a.h * 60 + a.m;
    const int second = b.h * 60 + b.m;
    return std::abs(first - second);
}

bool earlier(const Time& a, const Time& b) {
    if (a.h != b.h) {
        return a.h < b.h;
    }
    return a.m < b.m;
}

int main() {
    const Time departure(9, 45);
    const Time arrival(13, 10);
    std::cout << minutesBetween(departure, arrival) << ' '
              << std::boolalpha
              << earlier(arrival, departure) << '\n';

    const Time sameA(12, 0);
    const Time sameB(12, 0);
    const Time beforeNoon(11, 55);
    const Time afterNoon(12, 5);

    std::cout << minutesBetween(sameA, sameB) << ' '
              << earlier(sameA, sameB) << '\n';
    std::cout << minutesBetween(beforeNoon, afterNoon) << ' '
              << earlier(beforeNoon, afterNoon) << '\n';
    return 0;
}
