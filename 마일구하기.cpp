#include <iostream>
double mile = 0.0;
double kmtomile(double mile)
{
	double km = mile * 1.60934;
	return km;
}
int main()
{
	std::cout << "���ϰ��� �Է�";
	std::cin >> mile;
	std::cout << "km��ȯ��" << kmtomile(mile) << "km�Դϴ�" << std::endl;


}

