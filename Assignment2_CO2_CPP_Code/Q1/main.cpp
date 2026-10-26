#include <iostream>

void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    if (c != nullptr) {
        *c += 10;
    }
}

int& bigger(int& p, int& q) {
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    std::cout << x + y + z << ' ';
}

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) {
        *fee -= *fee * percent / 100;
    }
}

long long concessionReturningValue(long long fee, int percent) {
    return fee - fee * percent / 100;
}

int main() {
    int a = 1, b = 2, c = 3;
    change(a, b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    std::cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    std::cout << '\n';

    long long hostelFee = 45000;
    applyByValue(hostelFee, 10);
    std::cout << "after call by value : " << hostelFee << '\n';

    applyConcession(hostelFee, 10);
    std::cout << "after call by reference: " << hostelFee << '\n';

    applyByPointer(&hostelFee, 10);
    std::cout << "after call by pointer: " << hostelFee << '\n';

    hostelFee = concessionReturningValue(hostelFee, 10);
    std::cout << "after return-value version: " << hostelFee << '\n';
    return 0;
}
