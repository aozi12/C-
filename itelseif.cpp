#include <iostream>
const int Fave = 27;
int main()
{
	int n;

	std::cout << "1���� 100���� �������� �ϳ��� ���� �˾Ƹ����� �����Դϴ�.\n";
	std::cout << "���� �����ϴ� ���� �����ϱ?";
	do
	{
		std::cin >> n;
		if (n < Fave)
			std::cout << "�װͺ��� Ů�ϴ�. �����ϱ?";
		else if (n > Fave)
			std::cout << "�װͺ��� �۽��ϴ�. �����ϱ��?";
		else
			std::cout << "�¾ҽ��ϴ�. ������" << Fave << "�Դϴ�.\n";
	} while (n != Fave);
	return 0;
}