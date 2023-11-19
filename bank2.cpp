#include <iostream>
#include "bank1.h"
#include <cstdlib>
#include <iomanip>
int main() {
    int numCustomers;
    std::cout << "만들 고객의 수를 입력하세요: ";
    std::cin >> numCustomers;
    
    //BankAccount customers[numCustomers];
    BankAccount* customers = new BankAccount[numCustomers];

    for (int i = 0; i < numCustomers; ++i) {
        std::string name, accountNumber, phoneNumber, address;
        int pin;
        double deposit;
        int creditRating;
            char gender;

        std::cout << "\n고객 #" << i + 1 << " 정보 입력" << std::endl;
        std::cout << "이름: ";
        std::cin >> name;
        std::cout << "계좌번호: ";
        std::cin >> accountNumber;
        std::cout << "핀번호: ";
        std::cin >> pin;
        std::cout << "예금액: ";
        std::cin >> deposit;
        if (deposit >= 200'000'000)
            creditRating = 1;
        else if (deposit >= 100'000'000)
            creditRating = 2;
        else if (deposit >= 50'000'000)
            creditRating = 3;
        else
            creditRating = 4;

        std::cout << "신용등급: " << creditRating << std::endl;
        //std::cin >> creditRating;
        std::cout << "성별 (M/F): ";
        std::cin >> gender;
        std::cout << "전화번호: ";
        std::cin >> phoneNumber;
        std::cout << "집주소: ";
        std::cin >> address;

        customers[i].setInfo(name, accountNumber, pin, deposit, creditRating, gender, phoneNumber, address);
    }

    // 추가 기능 구현
    while (true) {
        system("cls");
        std::cout << "\n[메뉴]\n";
        std::cout << "1. 이름으로 고객 정보 찾기\n";
        std::cout << "2. 가장 많은 예금을 가진 고객 찾기\n";
        std::cout << "3. 입금\n";
        std::cout << "4. 출금\n";
        std::cout << "5. 잔액 조회\n";
        std::cout << "6. 계좌번호로 개인정보 검색\n";
        std::cout << "7. 이름, 전화번호로 계좌번호 찾기\n";
        std::cout << "8. 종료\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // 이름으로 고객 정보 찾기
            std::string searchName;
            std::cout << "찾을 고객 이름을 입력하세요: ";
            std::cin >> searchName;
           

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getName() == searchName) {
                    std::cout << "고객 정보:\n";
                    std::cout << "이름: " << customers[i].getName() << "\n";
                    std::cout << "계좌번호: " << customers[i].getAccountNumber() << "\n";
                    std::cout << "잔액: " << customers[i].getBalance() << "\n";
                    std::cout << "신용등급: " << customers[i].getCreditRating() << "\n";
                    std::cout << "성별: " << customers[i].getGender() << "\n";
                    std::cout << "전화번호: " << customers[i].getPhoneNumber() << "\n";
                    std::cout << "집주소: " << customers[i].getAddress() << "\n";
                    break;
                }
            }
            std::cin.get();

        }
        else if (choice == 2) {
            // 가장 많은 예금을 가진 고객 찾기
            double maxDeposit = -1;
            int maxDepositIndex = -1;

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getBalance() > maxDeposit) {
                    maxDeposit = customers[i].getBalance();
                    maxDepositIndex = i;
                
                }
            }

            if (maxDepositIndex != -1) {
                std::cout << "가장 많은 예금을 가진 고객:\n";
                std::cout << "이름: " << customers[maxDepositIndex].getName() << "\n";
                std::cout << "계좌번호: " << customers[maxDepositIndex].getAccountNumber() << "\n";
                std::cout << std::fixed << std::setprecision(0) << "잔액: " << customers[maxDepositIndex].getBalance() << "\n";
            }
            std::cin.get();
        }
        else if (choice == 3) {
            // 입금
            std::string accountNumber;
            double amount;
            std::cout << "입금할 계좌번호를 입력하세요: ";
            std::cin >> accountNumber;

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getAccountNumber() == accountNumber) {
                    std::cout << "입금할 금액을 입력하세요: ";
                    std::cin >> amount;
                    if (amount > 0) {
                        customers[i].deposit(amount);
                        std::cout << "입금이 완료되었습니다.\n";
                    }
                    else {
                        std::cout << "올바른 금액을 입력하세요.\n";
                    }
                    break;
                }
            }
            std::cin.get();
        }
        else if (choice == 4) {
            // 출금
            std::string accountNumber;
            double amount;
            std::cout << "출금할 계좌번호를 입력하세요: ";
            std::cin >> accountNumber;

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getAccountNumber() == accountNumber) {
                    std::cout << "출금할 금액을 입력하세요: ";
                    std::cin >> amount;
                    if (amount > 0 && customers[i].withdraw(amount)) {
                        std::cout << "출금이 완료되었습니다.\n";
                    }
                    else {
                        std::cout << "올바른 금액을 입력하거나 잔액이 부족합니다.\n";
                    }
                    break;
                }
            }
            std::cin.get();
        }
        else if (choice == 5) {
            // 잔액 조회
            std::string accountNumber;
            int pinAttempt;
            std::cout << "잔액을 조회할 계좌번호를 입력하세요: ";
            std::cin >> accountNumber;
            std::cout << "핀번호를 입력하세요: ";
            std::cin >> pinAttempt;

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getAccountNumber() == accountNumber) {
                    double balance = customers[i].checkBalance(pinAttempt);
                    if (balance != -1) {
                        std::cout << std::fixed << std::setprecision(0) << "잔액: " << balance << "\n";
                    }
                    else {
                        std::cout << "잘못된 핀번호입니다.\n";
                    }
                    break;
                }
            }
            std::cin.get();
        }
        else if (choice == 6) {
            // 계좌번호로 개인정보 검색
            std::string accountNumber;
            std::cout << "검색할 계좌번호를 입력하세요: ";
            std::cin >> accountNumber;

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getAccountNumber() == accountNumber) {
                    std::cout << "고객 정보:\n";
                    std::cout << "이름: " << customers[i].getName() << "\n";
                    std::cout << "계좌번호: " << customers[i].getAccountNumber() << "\n";
                    std::cout << std::fixed << std::setprecision(0) << "잔액: " << customers[i].getBalance() << "\n";
                    std::cout << "신용등급: " << customers[i].getCreditRating() << "\n";
                    std::cout << "성별: " << customers[i].getGender() << "\n";
                    std::cout << "전화번호: " << customers[i].getPhoneNumber() << "\n";
                    std::cout << "집주소: " << customers[i].getAddress() << "\n";
                    break;
                }
            }
            std::cin.get();
        }
        else if (choice == 7) {
            // 이름, 전화번호로 계좌번호 찾기
            std::string searchName, searchPhoneNumber;
            std::cout << "찾을 고객 이름을 입력하세요: ";
            std::cin >> searchName;
            std::cout << "찾을 고객 전화번호를 입력하세요: ";
            std::cin >> searchPhoneNumber;

            for (int i = 0; i < numCustomers; ++i) {
                if (customers[i].getName() == searchName && customers[i].getPhoneNumber() == searchPhoneNumber) {
                    std::cout << "찾은 계좌번호: " << customers[i].getAccountNumber() << "\n";
                    break;
                }
            }
            std::cin.get();
        }
        else if (choice == 8) {
            // 종료
            break;
        }
        std::cin.get();
    }

    delete[] customers; // 동적 할당한 메모리 해제

    return 0;
}