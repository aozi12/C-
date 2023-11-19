
#include <iostream>

int main()
{
    std::cout << "지금 사시는 아파트에 언제 입주했어?\n";
    int year;
    std::cin >> year;
    std::cin.get();
    std::cout << "사시는 도시를 말씀해주셈\n";
    char address[80];
    std::cin.get(address, 80).get();
    std::cout << "아파트 입주 연도:" << year << std::endl;
    std::cout << "도시: " << address << std::endl;
    std::cout << "등록 완료!\n";
    return 0;


}
   /* const uint32_t SIZE{20};
    char name[SIZE]{};
    char dessert[SIZE]{};

    std::cout << "이름\n";
    std::cin.get(name, SIZE).get();
    std::cout << "디저트\n";
    std::cin.get(dessert, SIZE).get();
    std::cout << "준비" << name << std::endl;
    std::cin.get(name, SIZE).get();
    //std::cin.getline(name, SIZE).getline(dessert).getline();
    //return 0;
}*/

