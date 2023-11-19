#include <iostream>

int main()
{	
	int values[] = { 1,2 ,3 };
	values[0];
	int number1 = 100;
	int number2 = 200;
	int  number3 = 300;
	int * numbers[3] = {&number1, &number2, &number3};
	*numbers[0];
	*(*(numbers + 0));
	const char* strs[] = {"Hello", "World", "Android"};
	//{const char*, const char*, const char*}
	//*strs[0] == *(*(strs +0))
	return 0;
}