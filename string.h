#pragma once
#include <iostream>
class String
{
private:
	char* str;
	unsigned int length;
	static unsigned int numberOfObjcet;
public:
	static unsigned int get_numberOfObjcet()
	{
		return String::numberOfObjcet;
	}

	String();
	~String();
	String(const char* str);
	char* get_str();
	friend std::ostream& operator<<(std::ostream& os, const String& rhs);
	String(const String& rhs);
	String& operator=(const String& rhs);


};

