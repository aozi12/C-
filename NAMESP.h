#pragma once
#include <iostream>
namespace Pers
{
    struct Person
    {
        std::string first_name;
        std::string last_name;

    };
    void getPerson(Person&);
    void showPerson(const Person&);
}

namespace Debts
{
    using namespace Pers;
    struct Debt
    {
        Pers::Person name;
        double amount;
    };

    void getDebt(Debt&);
    void showDebt(const Debt&);
    double sumDebt(const Debt amount[], int number);
}