# Task 6 – Pseudocode and Control Structures

```text
START
Read zone, hour and balance
If zone/hour invalid: reject
peak = (8 <= hour < 10) OR (17 <= hour < 20)
Use switch(zone) to select base fare
If peak: fare = base + base * 20 / 100
Else: fare = base
If balance - fare >= 5000:
    deduct fare and print fare/balance
Else:
    deny journey and keep balance unchanged
END
```

Expected initial three-trip output:
```text
Fare Rs 10.00 balance Rs 90
Fare Rs 36.00 balance Rs 54
Denied (low balance) balance Rs 54
```
