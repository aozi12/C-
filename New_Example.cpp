// New_Example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
int value1 = 100;
int value;
static int value2 = 10;

int main()
{
	int * ptr_heap = new int;		//4바이트하나를 받아온다는뜻 = c의 malloc
	if (ptr_heap == nullptr) {
		std::cout << "메모리가없다" << std::endl;
		return 1;
	}
	std::cout << ptr_heap << std::endl;
	*ptr_heap = 100;
}

