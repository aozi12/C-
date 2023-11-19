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

//�Լ�
// ���� �̸� ã�� ���
int findCustomerByName(const BankAccount* bankAccounts, int numCustomers, const std::string& name) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getName() == name) {
            return i;
        }
    }
    return -1; // �̸��� ���� ���
}

// ���� �� ���� ���� ������ ���� ��� ã��
int findCustomerWithMaxDeposit(const BankAccount* bankAccounts, int numCustomers) {
    int maxIndex = 0;
    for (int i = 1; i < numCustomers; ++i) {
        if (bankAccounts[i].getBalance() > bankAccounts[maxIndex].getBalance()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// �Ա�(���̳ʽ� �ݾ��Է� �õ� - ����)
void depositMoney(BankAccount& account, double amount) {
    if (amount > 0) {
        account.deposit(amount);
    }
    else {
        std::cout << "�߸��� �Աݾ��Դϴ�." << std::endl;
    }
}

// ��� (�ܾ׺��� ���� ��� �õ� - ����)
bool withdrawMoney(BankAccount& account, double amount) {
    if (amount > 0 && account.getBalance() >= amount) {
        account.withdraw(amount);
        return true;
    }
    std::cout << "����� �� �����ϴ�." << std::endl;
    return false;
}

// �ܾ���ȸ�� �н����� ����� �ϱ�
void checkBalanceWithPassword(const BankAccount& account) {
    int pinAttempt;
    std::cout << "�ܾ��� Ȯ���� �� �н����带 �Է��ϼ���: ";
    std::cin >> pinAttempt;
    double balance = account.checkBalance(pinAttempt);
    if (balance != -1) {
        std::cout << "�ܾ�: " << balance << "��" << std::endl;
    }
    else {
        std::cout << "�н����尡 �ùٸ��� �ʽ��ϴ�." << std::endl;
    }
}

// �ܾ� �������� ��� ��ȯ
std::string getBalanceGrade(double balance) {
    if (balance >= 200000000) {
        return "1���";
    }
    else if (balance >= 100000000) {
        return "2���";
    }
    else if (balance >= 50000000) {
        return "3���";
    }
    return "�Ϲ� ���";
}

// ���¹�ȣ�� �������� �˻�
int findCustomerByAccountNumber(const BankAccount* bankAccounts, int numCustomers, const std::string& accountNumber) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1; // ���¹�ȣ�� ���� ���
}

// �̸����� ���¹�ȣ ã��
std::string findAccountNumberByName(const BankAccount* bankAccounts, int numCustomers, const std::string& name) {
    int index = findCustomerByName(bankAccounts, numCustomers, name);
    if (index != -1) {
        return bankAccounts[index].getAccountNumber();
    }
    return "ã�� �� ����";
}

// ��ȭ��ȣ�� ���¹�ȣ ã��
std::string findAccountNumberByPhoneNumber(const BankAccount* bankAccounts, int numCustomers, const std::string& phoneNumber) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getPhoneNumber() == phoneNumber) {
            return bankAccounts[i].getAccountNumber();
        }
    }
    return "ã�� �� ����";
}

// �ּҷ� ���¹�ȣ ã��
std::string findAccountNumberByAddress(const BankAccount* bankAccounts, int numCustomers, const std::string& address) {
    for (int i = 0; i < numCustomers; ++i) {
        if (bankAccounts[i].getAddress() == address) {
            return bankAccounts[i].getAccountNumber();
        }
    }
    return "ã�� �� ����";
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
        std::cout << "1���" << std::endl;
        return "1";
    }
    else if (balance >= 100000000) {
        std::cout << "2���" << std::endl;
        return "2";
    }
    else if (balance >= 50000000) {
        std::cout << "3���" << std::endl;
        return "3";
    }
    return "Regular";
}