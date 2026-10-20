# Task 12 – Day-4 Design Challenge

## A. Impact analysis
- Add `Airport` and a ₹60 fare (6000 paise).
- Add weekend flag and 10% discount.
- Weekend discount must not combine with peak surcharge.
- Add `Pass` with active status and two covered zones.
- Keep `SmartCard` balance private and enforce the minimum balance for paid trips.

## B. Evaluate original design
A switch can add Airport with another case, but every zone extension requires source changes. A fare table is easier to extend. A valid pass should bypass fare deduction for covered zones, so pass logic should be separate from normal fare calculation.

## C. Worked examples
- Airport weekday off-peak: ₹60.
- Airport weekday peak: ₹72.
- Airport weekend: ₹54, even if the peak flag is true, because weekend discount takes precedence and does not combine with surcharge.
- A valid pass covering Airport permits the trip without deducting a normal fare.

## D. Defence and complexity
The table-driven policy and separate Pass class are easier to maintain. Fare lookup and pass coverage are O(1); processing n journeys is O(n). The demo uses an active flag only. A production system should add start/end dates, pass expiry, renewal, and robust validation. Execute the program and preserve the output as evidence.
