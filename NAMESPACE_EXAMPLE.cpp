#include <iostream>
#include "NAMESP.h"
int main()
{
	Pers::Person person;
	person.first_name = "KarL";
	std::cout << person.first_name;

	person.first_name = "Choi";
	std::cout << person.first_name;
	std::cout << person.last_name;

}
