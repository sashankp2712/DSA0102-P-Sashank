#include <array>
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

class SavingsAccount {
private:
    std::string accountNumber_;
    long long balancePaise_;
    std::array<long long, 10> transactions_{};
    std::size_t next_ = 0;
    std::size_t count_ = 0;

    void record(long long amountPaise) {
        transactions_[next_] = amountPaise;
        next_ = (next_ + 1) % transactions_.size();
        if (count_ < transactions_.size()) {
            ++count_;
        }
    }

public:
    SavingsAccount(std::string accountNumber, long long openingBalancePaise)
        : accountNumber_(std::move(accountNumber)),
          balancePaise_(openingBalancePaise) {}

    bool deposit(long long amountPaise) {
        if (amountPaise <= 0) {
            return false;
        }
        balancePaise_ += amountPaise;
        record(amountPaise);
        return true;
    }

    bool withdraw(long long amountPaise) {
        if (amountPaise <= 0 || amountPaise > balancePaise_) {
            return false;
        }
        balancePaise_ -= amountPaise;
        record(-amountPaise);
        return true;
    }

    long long balance() const {
        return balancePaise_;
    }

    void miniStatement() const;
};

void SavingsAccount::miniStatement() const {
    std::cout << "Account: " << accountNumber_ << '\n';
    std::cout << "Balance: " << balancePaise_ << " paise\n";
    std::cout << "Recent transactions (paise; negative = withdrawal):\n";

    const std::size_t oldest =
        (next_ + transactions_.size() - count_) % transactions_.size();

    for (std::size_t i = 0; i < count_; ++i) {
        std::cout << transactions_[(oldest + i) % transactions_.size()] << '\n';
    }
}

int main() {
    SavingsAccount account("SA1001", 10000);
    account.deposit(2500);
    account.withdraw(1000);

    for (int i = 1; i <= 10; ++i) {
        account.deposit(100 * i);
    }

    account.miniStatement();
    return 0;
}
