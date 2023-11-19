#include <iostream>
#include <string>

int main()
{
	std::string word = "?ate";
	for (char ch = 'a'; word != "mate"; ch++)
	{
		std::cout << word << std::endl;
		word[0] = ch;
	}
	std::cout << "루프가 끝난 후에 단어는" << word << "입니다.\n";
	return 0;
}