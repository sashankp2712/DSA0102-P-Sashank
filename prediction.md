# Task 5 – Operators and Precedence

## Predicted output (predict before running)
```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

- Multiplication has higher precedence than addition: `5 + 3 * 2 = 11`.
- Parentheses force `(5 + 3) * 2 = 16`.
- `x++` contributes old x (5), then x becomes 6; `++y` increments y to 4 and contributes 4. Thus z = 9.
- The conditional expression returns the larger value, 6. `%` and `*` have equal precedence and associate left-to-right: `6 % 4 * 2 = 4`.
- Integer division truncates toward zero: `10/3 = 3`, `-10/3 = -3`. Remainders are 1 and -1.
- The loop adds 0 + 3 + 6 + 9 = 18.

Peak rule: `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. The table alternative uses about 24 bool entries and remains O(1) per lookup.
