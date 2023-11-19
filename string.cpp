#include "string.h"
// + 巩磊凯 钦窍扁
unsigned int String::numberOfObjcet = 0;

String::String()
{
	++String::numberOfObjcet;
	std::cout << "String() 按眉 积己" << std::endl;
	this->length = 0;
	this->str = new char[1];
	std::cout << String::get_numberOfObjcet() << std::endl;
}
String::~String()
{
	--String::numberOfObjcet;
	std::cout << "~String() 按眉 家戈" << std::endl;
	this->length = 0;
	delete[]this->str;
	std::cout << String::get_numberOfObjcet() << std::endl;
}
String::String(const char* str)
{
	++String::numberOfObjcet;
	std::cout << "String(const char*) 按眉 积己" << std::endl;
	this->length = strlen(str) +1 ;
	this->str = new char[length];
	strcpy_s(this->str, length, str);	
}
char* String::get_str()
{
	return this->str;
}
std::ostream& operator<<(std::ostream& os, const String& rhs)
{
	os << rhs.str;
	return os;
}

String::String(const String& rhs)
{

	this->length = rhs.length + 1;
	this->str = new char[length];
	strcpy_s(this->str, this->length, rhs.str);
	++String::numberOfObjcet;
	std::cout << String::numberOfObjcet << std::endl;
}
String& String::operator=(const String& rhs)
{
	if (this == &rhs) return *this;
	delete[] this->str;
	this->length = rhs.length + 1;
	this->str = new char[this->length];
	strcpy_s(this->str, this->length, rhs.str);
	return *this;
}