# Task 8 – Safe Input and Output

`cin` extraction can fail for text input where a number is expected. On failure, call `cin.clear()` and discard the invalid line with `cin.ignore(numeric_limits<streamsize>::max(), '\n')`. Then validate the range as well. Money formatting uses integer division and remainder to print two paise digits.

An alternative is `getline()` followed by `stoi()` inside `try/catch`. Processing a line of length L is O(L) in either approach; `getline` needs O(L) buffer space. `stoi` should be checked for invalid input and trailing characters.
