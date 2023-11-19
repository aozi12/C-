#include <iostream>
int age = 0;
int agetomonth(int age)
{
	
	return age*12;
}
int main()
{
	std::cout << "당신의 나이 입력";
	std::cin >> age;
	std::cout << "month로환산" << agetomonth(age) << "입니다" << std::endl;


}

