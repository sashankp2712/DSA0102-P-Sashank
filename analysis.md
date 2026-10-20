# Task 1 – Understand the Problem and Identify the Objects

## Objects and responsibilities
- **SmartCard:** stores card ID and balance; validates and deducts fare.
- **Passenger:** stores passenger identity/category; may qualify for a concession.
- **Journey:** stores zone, hour, and travel details.
- **Zone:** identifies Inner, Middle, Outer (later Airport).
- **FareTable/FarePolicy:** centralizes fares, surcharge, and discounts.

## OOP principles
- **Encapsulation:** SmartCard's balance should be private and changed only by checked methods.
- **Abstraction:** callers use `fare()` and `canTravel()` without knowing the internal calculation.
- **Inheritance:** StudentPassenger and SeniorPassenger could derive from Passenger if they have distinct concession policies.
- **Polymorphism:** a virtual `concession()` method could dispatch to the passenger-specific policy.

## Rules/invariants
1. Balance must never become negative.
2. A paid journey must leave at least ₹50 (5000 paise).
3. A denied journey does not change the balance.
4. Unknown zones and invalid hours are rejected.
5. Money calculations use integer paise.

The prompt mentions student and senior concessions but does not specify rates, so this repository does not invent concession percentages.

## Procedural vs OOP
A procedural design uses separate variables and free functions. An OOP design groups state and behaviour into classes. Both can calculate a fare in O(1) time and store one card in O(1) space. OOP improves encapsulation and change management, not the asymptotic cost of a fare calculation.
