#include <iostream>
#include "String.h"
int main()
{
	String str0{ String() };
	String str1{ String("Android") };
	std::cout << str1 << std::endl;
	String str2 = "Apple";
	std::cout << str2 << std::endl;
	String str3 = str2;
	std::cout << str3 << std::endl;
	String str4 = "iOS";
	str4 = str1;
	std::cout << str4 << std::endl;
}

