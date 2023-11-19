//재귀 호출

#include <iostream>
void countdown(int);

int main()
{
    countdown(2);/*깃발0*/       //countdown함수 루프를 끝내고 다시 돌아올 위치
    std::cout << std::endl;
}

void countdown(int number)  //2가 복사되어 내려 옴
{
    /*1*/std::cout << "카운트 다운" << std::endl;     //
    /*2*/if (number > 0) countdown(number - 1)/*깃발1*/;      //if 조건 반복 후 깃발1로 돌아옴

    /*3*/std::cout << number/*깃발2*/ << ": Koboom!!" << std::endl;   //if문 조건을 해당하지 않으면 다시 돌아올 위치 깃발2
}   //countdown이 0이 된다면 '}' 리턴을 만나고, 다시 number(깃발2)로 되돌아간다.


//재귀 호출

#include <iostream>
void countdown(int);

int main()
{
    countdown(2);
    std::cout << std::endl;
}

void countdown(int number)  
{
    std::cout << "카운트 다운" << std::endl;     
    if (number > 0) countdown(number - 1);      

    std::cout << number << ": Koboom!!" << std::endl;   
}   