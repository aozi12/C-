
#include <iostream>
void simon(int);
int main()
{
	simon(3);
	std::cout << "정수를 하나골라봐";
		int count;
	std::cin >> count;
	simon(count);
std::cout << "gg" << std::endl;
	return 0;
}
void simon(int n)
{
	std::cout << "Simon 왈, 발가락을" << n << "번 두드려라" << std::endl;
}