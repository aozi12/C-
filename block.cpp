#include <iostream>

int main()
{
	std::cout << "값 5개의 합계와 평균을 구합니다.\n";
	std::cout << "값 5개를 입력하시오.\n";
	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5; i++)
	{
		std::cout << "값 " << i << ": ";
		std::cin >> number;
		sum += number;

	}
	std::cout << "값 5개가 모두 입력되었습니다.\n";
	std::cout << "입력한 값 5개의 합계는" << sum << "입니다	.\n";
	std::cout << "입력한 값 5개의 평균은" << sum / 5 << "입니다.\n";
	std::cout << "감사합니다.\n";
	return 0;


}