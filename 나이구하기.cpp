#include <iostream>
int age = 0;
int agetomonth(int age)
{
	
	return age*12;
}
int main()
{
	std::cout << "����� ���� �Է�";
	std::cin >> age;
	std::cout << "month��ȯ��" << agetomonth(age) << "�Դϴ�" << std::endl;


}

