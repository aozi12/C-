#include <iostream>
const int Fave = 27;
int main()
{
	int n;

	std::cout << "1부터 100까지 범위에서 하나의 수를 알아맞히는 게임입니다.\n";
	std::cout << "내가 좋아하는 수는 무엇일까여?";
	do
	{
		std::cin >> n;
		if (n < Fave)
			std::cout << "그것보다 큽니다. 무엇일까여?";
		else if (n > Fave)
			std::cout << "그것보다 작습니다. 무엇일까요?";
		else
			std::cout << "맞았습니다. 정답은" << Fave << "입니다.\n";
	} while (n != Fave);
	return 0;
}