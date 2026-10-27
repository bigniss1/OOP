#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string number;
    double balance;

public:
    BankAccount(const std::string& accountNumber, double money)
        : number(accountNumber), balance(money) {
    }

    void print() const {
        std::cout << "Account " << number
                  << ", balance " << balance << '\n';
    }

    double calculateIncome() const {
        return 0;
    }
};

class DebitAccount : public BankAccount {
private:
    double monthlyFee;

public:
    DebitAccount(const std::string& number, double balance, double fee)
        : BankAccount(number, balance), monthlyFee(fee) {
    }

    double calculateIncome() const {
        return -monthlyFee;
    }
};

class CreditAccount : public BankAccount {
private:
    double interestRate;

public:
    CreditAccount(const std::string& number, double balance, double rate)
        : BankAccount(number, balance), interestRate(rate) {
    }

    double calculateIncome() const {
        if (balance < 0) {
            return balance * interestRate / 100;
        }

        return 0;
    }
};

class DepositAccount : public BankAccount {
private:
    double interestRate;

public:
    DepositAccount(const std::string& number, double balance, double rate)
        : BankAccount(number, balance), interestRate(rate) {
    }

    double calculateIncome() const {
        return balance * interestRate / 100;
    }
};

int main() {
    DebitAccount debit("001", 1000, 20);
    CreditAccount credit("002", -2000, 3);
    DepositAccount deposit("003", 5000, 10);

    BankAccount* account = &debit;
    account->print();
    std::cout << "Debit: change "
              << debit.calculateIncome() << "\n";

    account = &credit;
    account->print();
    std::cout << "Credit: change "
              << credit.calculateIncome() << "\n";

    account = &deposit;
    account->print();
    std::cout << "Deposit: income "
              << deposit.calculateIncome() << '\n';

    return 0;
}