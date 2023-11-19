#include <iostream>
#include <string>
#include "BANK.h"

class BankAccount {
private:
    std::string customerName;
    std::string accountNumber;
    int pin;
    double balance;
    int creditScore;
    char gender;
    std::string phoneNumber;
    std::string address;

    bool isLocked;
    int incorrectPinAttempts;

public:
    BankAccount() : balance(0.0), creditScore(0), isLocked(false), incorrectPinAttempts(0) {}

    // Setters
    void SetCustomerInfo(const std::string& name, const std::string& accNumber, int pin, char gender,
        const std::string& phone, const std::string& addr) {
        customerName = name;
        accountNumber = accNumber;
        this->pin = pin;
        this->gender = gender;
        phoneNumber = phone;
        address = addr;
    }

    // Deposit method
    void Deposit(double amount) {
        balance += amount;
        UpdateCreditScore();
    }

    // Withdraw method
    bool Withdraw(double amount, int inputPin) {
        if (isLocked) {
            std::cout << "Account is locked. Contact customer service." << std::endl;
            return false;
        }

        if (inputPin != pin) {
            incorrectPinAttempts++;
            if (incorrectPinAttempts >= 3) {
                isLocked = true;
                std::cout << "Account is locked due to too many incorrect PIN attempts." << std::endl;
            }
            else {
                std::cout << "Incorrect PIN. Attempts remaining: " << 3 - incorrectPinAttempts << std::endl;
            }
            return false;
        }

        if (amount > balance) {
            std::cout << "Insufficient balance." << std::endl;
            return false;
        }

        balance -= amount;
        UpdateCreditScore();
        return true;
    }

    // Balance inquiry method
    double GetBalance(int inputPin) {
        if (inputPin != pin) {
            std::cout << "Incorrect PIN. Please provide correct PIN to continue." << std::endl;
            return -1.0;
        }

        return balance;
    }

    // Get customer name
    std::string GetCustomerName() const {
        return customerName;
    }

    // Update credit score based on balance
    void UpdateCreditScore() {
        if (balance >= 200000000) {
            creditScore = 1;
        }
        else if (balance >= 100000000) {
            creditScore = 2;
        }
        else if (balance >= 50000000) {
            creditScore = 3;
        }
        else {
            creditScore = 4;
        }
    }
};

int main() {
    int numCustomers;
    std::cout << "Enter the number of customers: ";
    std::cin >> numCustomers;

    BankAccount customers[numCustomers];

    for (int i = 0; i < numCustomers; ++i) {
        std::string name, accNumber, phone, addr;
        int pin;
        char gender;

        std::cout << "Enter customer #" << i + 1 << " information:" << std::endl;
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Account Number: ";
        std::cin >> accNumber;
        std::cout << "PIN: ";
        std::cin >> pin;
        std::cout << "Gender (M/F): ";
        std::cin >> gender;
        std::cout << "Phone Number: ";
        std::cin >> phone;
        std::cout << "Address: ";
        std::cin.ignore(); // Clear newline character from previous input
        std::getline(std::cin, addr);

        customers[i].SetCustomerInfo(name, accNumber, pin, gender, phone, addr);
    }

    // Additional features and methods can be added here based on your requirements

    return 0;
}