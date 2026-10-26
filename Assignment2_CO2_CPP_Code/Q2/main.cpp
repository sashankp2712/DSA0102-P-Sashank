#include <iostream>
#include <vector>

int& highestMark(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[best]) {
            best = i;
        }
    }
    return marks[best];
}

int highestIndex(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[best]) {
            best = i;
        }
    }
    return best;
}

int* highestPointer(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (marks[i] > marks[best]) {
            best = i;
        }
    }
    return &marks[best];
}

// Do not return a reference to a local variable.
// int& brokenReference() {
//     int local = 10;
//     return local; // dangling reference / undefined behaviour
// }

int main() {
    int marks[] = {78, 91, 84, 88};

    highestMark(marks, 4) += 2;
    std::cout << "Highest after moderation: "
              << highestMark(marks, 4) << '\n';

    int index = highestIndex(marks, 4);
    std::cout << "Index: " << index
              << ", mark: " << marks[index] << '\n';

    int* ptr = highestPointer(marks, 4);
    if (ptr != nullptr) {
        std::cout << "Pointer result: " << *ptr << '\n';
    }

    std::vector<int> growingMarks{78, 91, 84};
    int savedIndex = 1;
    growingMarks.push_back(99);
    // Re-read by index after growth; old pointers/references may be invalidated.
    std::cout << "After vector growth, mark at saved index: "
              << growingMarks[savedIndex] << '\n';
    return 0;
}
