# Task 10 – Expectations vs Execution

Run `main.cpp`, save the actual output and compare it with the expected total. For 3,000,000 journeys at ₹30 each, the mathematical total is ₹90,000,000 or 9,000,000,000 paise. A typical 32-bit signed `int` cannot hold that paise total. `long long` can. Record compiler warnings exactly as emitted; do not invent warnings.

Compile:
```bash
g++ --version
g++ -std=c++17 -Wall -Wextra -Wconversion main.cpp -o task10
./task10
```
