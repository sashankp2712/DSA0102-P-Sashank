# Assignment 2 – CO2 C++ Source Code

Replace student details and repository URL as needed.

## Folders
- `Q1/main.cpp`: value/reference/pointer, return by reference, defaults, concession code
- `Q2/main.cpp`: highest mark by reference, index and pointer
- `Q3/main.cpp`: default arguments and non-ambiguous overloads
- `Q4/main.cpp`: SavingsAccount with circular transaction history
- `Q5/main.cpp`: static BusTicket class and `token_prediction.cpp`
- `Q6/main.cpp`: friend functions for Time; `inline_benchmark.cpp` for timing
- `Q7/main.cpp`: circular-buffer redesign challenge

## Compile and run
Example:
```bash
g++ -std=c++17 -Wall -Wextra Q1/main.cpp -o q1
./q1
```
Compile each source file separately. For Q6 timing:
```bash
g++ -std=c++17 -O0 -Wall -Wextra Q6/inline_benchmark.cpp -o bench_O0
g++ -std=c++17 -O2 -Wall -Wextra Q6/inline_benchmark.cpp -o bench_O2
./bench_O0
./bench_O2
```

Repository required by the assignment: `DSA01-<RegisterNumber>-Assignment2`.

Run all programs yourself, save actual output screenshots in the corresponding folders, and record real timing/compiler information. Do not present predicted outputs as observed results.
