#include <iostream>
double mile = 0.0;
double kmtomile(double mile)
{
	double km = mile * 1.60934;
	return km;
}
int main()
{
	std::cout << "마일값을 입력";
	std::cin >> mile;
	std::cout << "km로환산" << kmtomile(mile) << "km입니다" << std::endl;


}

