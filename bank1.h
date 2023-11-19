#pragma once
#include <iostream>
#include <string>

class BankAccount {
public:
    BankAccount();

    void setInfo(std::string name, std::string accountNumber, int pin, double deposit, char credit, char gender, std::string phoneNumber, std::string address);

    std::string getName() const;
    std::string getAccountNumber() const;
    double getBalance() const;
    int getCreditRating() const;
    char getGender() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;

    void deposit(double amount);
    bool withdraw(double amount);
    double checkBalance(int pinAttempt) const;
    std::string getDepositGrade() const;

private:
    std::string name;
    std::string accountNumber;
    int pin;
    long long balance;
    int creditRating;
    char gender;
    std::string phoneNumber;
    std::string address;
};