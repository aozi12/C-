

#include <iostream>

int main()
{
	const char* rose = "Rose";   // R o s e 0
	char flower[10] = "Rose";	// R o s e 0

	char* ptr_heap =new char[10];
	if (!ptr_heap) {
		std::cout <<"메모리 부족" << std::endl;
		return 1;
	}
	for (int i = 0; i < sizeof flower / sizeof flower[0]; ++i)
	{
		ptr_heap[i] = flower[i];
	}
		//ptr_heap = flower; 실행불가
		delete[] ptr_heap; 
}

