// Stack_Global_Free.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
static int value1 = 100000;
static int value2 = 200000;
int main()
{	
	int value1 = 10;
	int value2 = 20;
	{	
		for (int i = 0; i < 10; ++i) {
			static int value = 10;
			std::cout << value << std::endl;
			++value;
		}
	}
	int value3 = 300;
	
	std::cout << value1 << std::endl;
	std::cout << value2 << std::endl;
	return 0;
}

