// fun_otr'.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
double gildong(int);
double moonsoo(int);

void estimate(int lines, double (*pf)(int));

int main()
{
    int code;
    std::cout << "필요한 코드의 행 수를 입력하십시오:";
    std::cin >> code;
    std::cout << "홍길동의 시간예상:\n";
    estimate(code, gildong);
    std::cout << "박문수의 시간예상:\n";
    estimate(code, moonsoo);
    return 0;
}

double gildong(int lns)
{
    return 0.05 * lns;

}

double moonsoo(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
    std::cout << lines << "행을 작성하는 데 ";
    std::cout << (*pf)(lines) << "시간이 걸립니다.\n";
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
