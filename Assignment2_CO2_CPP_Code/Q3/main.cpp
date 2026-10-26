#include <iostream>

struct Parcel {
    double weightKg;
    bool express = false;
    bool insured = false;
};

// Weight in kilograms. Optional flags are trailing defaults.
double charge(double weightKg, bool express = false, bool insured = false) {
    double total = 40.0 + 12.0 * weightKg;
    if (express) {
        total += 20.0;
    }
    if (insured) {
        total += 10.0;
    }
    return total;
}

// Integer weight is interpreted as grams.
double charge(int weightGrams) {
    return charge(static_cast<double>(weightGrams) / 1000.0);
}

double charge(const Parcel& parcel) {
    return charge(parcel.weightKg, parcel.express, parcel.insured);
}

int main() {
    const Parcel parcel{2.0, true, true};

    std::cout << "charge(2) = " << charge(2) << '\n';
    std::cout << "charge(2.0) = " << charge(2.0) << '\n';
    std::cout << "charge(2.0f) = " << charge(2.0f) << '\n';
    std::cout << "charge(2.0, true) = " << charge(2.0, true) << '\n';
    std::cout << "charge(2.0, true, true) = "
              << charge(2.0, true, true) << '\n';
    std::cout << "charge(parcel) = " << charge(parcel) << '\n';
    return 0;
}
