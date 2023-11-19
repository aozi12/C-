#include "bank1.h"
BankAccount::BankAccount() {
    balance = 0;
    creditRating = 'A';
}

void BankAccount::setInfo(std::string name, std::string accountNumber, int pin, double deposit, char credit, char gender, std::string phoneNumber, std::string address) {
    this->name = name;
    this->accountNumber = accountNumber;
    this->pin = pin;
    this->balance = deposit;
    this->creditRating = credit;
    this->gender = gender;
    this->phoneNumber = phoneNumber;
    this->address = address;
}

//함수
// 고객의 이름 찾기 기능
int findCustomerByName(const BankAccount* bankAccounts, int numCustomers, const std::string& name) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getName() == name) {
            return i;
        }
    }
    return -1; // 이름이 없는 경우
}

// 고객들 중 가장 많은 예금을 가진 사람 찾기
int findCustomerWithMaxDeposit(const BankAccount* bankAccounts, int numCustomers) {
    int maxIndex = 0;
    for (int i = 1; i < numCustomers; ++i) {
        if (bankAccounts[i].getBalance() > bankAccounts[maxIndex].getBalance()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 입금(마이너스 금액입력 시도 - 막기)
void depositMoney(BankAccount& account, double amount) {
    if (amount > 0) {
        account.deposit(amount);
    }
    else {
        std::cout << "잘못된 입금액입니다." << std::endl;
    }
}

// 출금 (잔액보다 많은 출금 시도 - 막기)
bool withdrawMoney(BankAccount& account, double amount) {
    if (amount > 0 && account.getBalance() >= amount) {
        account.withdraw(amount);
        return true;
    }
    std::cout << "출금할 수 없습니다." << std::endl;
    return false;
}

// 잔액조회시 패스워드 물어보게 하기
void checkBalanceWithPassword(const BankAccount& account) {
    int pinAttempt;
    std::cout << "잔액을 확인할 때 패스워드를 입력하세요: ";
    std::cin >> pinAttempt;
    double balance = account.checkBalance(pinAttempt);
    if (balance != -1) {
        std::cout << "잔액: " << balance << "원" << std::endl;
    }
    else {
        std::cout << "패스워드가 올바르지 않습니다." << std::endl;
    }
}

// 잔액 기준으로 등급 반환
std::string getBalanceGrade(double balance) {
    if (balance >= 200000000) {
        return "1등급";
    }
    else if (balance >= 100000000) {
        return "2등급";
    }
    else if (balance >= 50000000) {
        return "3등급";
    }
    return "일반 등급";
}

// 계좌번호로 개인정보 검색
int findCustomerByAccountNumber(const BankAccount* bankAccounts, int numCustomers, const std::string& accountNumber) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1; // 계좌번호가 없는 경우
}

// 이름으로 계좌번호 찾기
std::string findAccountNumberByName(const BankAccount* bankAccounts, int numCustomers, const std::string& name) {
    int index = findCustomerByName(bankAccounts, numCustomers, name);
    if (index != -1) {
        return bankAccounts[index].getAccountNumber();
    }
    return "찾을 수 없음";
}

// 전화번호로 계좌번호 찾기
std::string findAccountNumberByPhoneNumber(const BankAccount* bankAccounts, int numCustomers, const std::string& phoneNumber) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getPhoneNumber() == phoneNumber) {
            return bankAccounts[i].getAccountNumber();
        }
    }
    return "찾을 수 없음";
}

// 주소로 계좌번호 찾기
std::string findAccountNumberByAddress(const BankAccount* bankAccounts, int numCustomers, const std::string& address) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getAddress() == address) {
            return bankAccounts[i].getAccountNumber();
        }
    }
    return "찾을 수 없음";
}
std::string BankAccount::getName() const {
    return name;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

double BankAccount::getBalance() const {
    return balance;
}

int BankAccount::getCreditRating() const {
    return creditRating;
}

char BankAccount::getGender() const {
    return gender;
}

std::string BankAccount::getPhoneNumber() const {
    return phoneNumber;
}

std::string BankAccount::getAddress() const {
    return address;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

double BankAccount::checkBalance(int pinAttempt) const {
    if (pinAttempt == pin) {
        return balance;
    }
    return -1;
}

std::string BankAccount::getDepositGrade() const {
    if (balance >= 200000000) {
        std::cout << "1등급" << std::endl;
        return "1";
    }
    else if (balance >= 100000000) {
        std::cout << "2등급" << std::endl;
        return "2";
    }
    else if (balance >= 50000000) {
        std::cout << "3등급" << std::endl;
        return "3";
    }
    return "Regular";
}