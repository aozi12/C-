#include <iostream>

int main()
{
	std::cout << "�ܾ �ϳ� �Է�";
	std::string word;
	std::cin >> word;
	char temporary;
	for(int i = word.size()-1, j = 0; \
		j < i; --i, ++j)
	{
		temporary = word[i];
		}
	std::cout << word << std::endl;
}