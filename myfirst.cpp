// MyFirst.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//using namespace std
int main(int argc, const char* argv[])

{


    printf("%d \r\n", argc);
    printf("%s \r\n", argv[0]);
    printf("%s \r\n", argv[1]);
    printf("%s \r\n", argv[2]);

    std::cout << argc << std::endl;
    std::cout << argv[0] << std::endl;
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;






    return 0;
}

//main();
