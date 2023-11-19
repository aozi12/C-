// NEW_STRUCT.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
struct Inflat
{
	char str_buffer[BUFSIZ];		//512
	float volume;		//4
	double price;		//8		-> total 524 bytes
};
int main()
{	
	Inflat inflat;
	// 변수-> == (*변수). 
	std::cout << sizeof inflat << std::endl;
	Inflat *  ptr_inflat = 	new Inflat; 
	std::cout << "글자를 입력";
	char temporary[BUFSIZ]{  };
	std::cin.getline(temporary, BUFSIZ);
	strcpy_s(ptr_inflat->str_buffer, BUFSIZ, temporary);
	float temp_volume = 0.0f;
	std::cout << "볼륨을 입력";
	std::cin >> temp_volume;
	ptr_inflat->volume = temp_volume;
	std::cout << "가격을 입력";
	double temp_price = 0.0;
	std::cin >> temp_price;
	ptr_inflat->price = temp_price;

	std::cout << ptr_inflat->str_buffer << std::endl;
	std::cout << ptr_inflat->volume << std::endl;
	std::cout << ptr_inflat->price << std::endl;

	delete[] ptr_inflat;
	//(*ptr_inflat).name //간다음에 .으로가야함
	//ptr_inflat->name = "Karl"; //오류가나겠죠?
	
}

