

#include <iostream>
#include <vector>
int main()
{   
   // 변수명을 복수
	// 선언과 동시에 초기화
	int yams[3]{ 1,2,3 };
	const char* ptrChar{ "Hello" }; 
	char str1[]{ "Hello" };//6 
	char str2[]{ 'H','e','l','l','o' }; //6
	char str3[] = "Hello" ;//5
	ptrChar = nullptr;


	//yams[0] = 2;
	//yams[1] = 3;
	//yams[2] = 4;
	
	//int yamcosts[3] = { 200, 300, 50 };
	//std::cout << "고구마합계 =";
	//std::cout << yams[0] + yams[1] + yams[2] << std::endl;
	//std::cout << yams[1] << "개가 들어 있는 포장은";
	//std::cout << "개당" << yamcosts[1] << "원씩입니다.\n";
	//int total = yams[0] * yamcosts[0] + yams[1] * yams[1];
	//total = total + yams[2] * yamcosts[2];
	//std::cout << "세 포장의 총 가격은" << total << "원입니다.\n";
	//std::cout << "\nyams 배열의 크기는" << sizeof yams;
	//std::cout << "바이트 ㅇ입니다.\n";
	//std::cout << "원소 하나의 크기는" << sizeof yams[0];
	//std::cout << "바이트 입니다.\n";

	
	//int value1 = 10;
	//int value2 = 20;
	//i//nt humans[] = { 1,2,3,4,5,6,7 };
	//int* ptr = humans;
	//ptr = &value2;
	//std::cout << *humans << std::endl;
	//std::cout << humans[0] << std::endl;
	
	return 0;
}   

