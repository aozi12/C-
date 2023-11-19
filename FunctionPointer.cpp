// FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
int func(int, int);
int func2(int, int);
int* func3(int, int);       //함수
int (*ptr_functor)(int, int);       //함수포인터

int func_pointer(int(*ptr_param)(int, int));
int main()
{
    int value_a = 20;
    int value_b = 30;
    int result = func(value_a, value_b);
    std::cout << result << std::endl;

    int(*ptr_func)(int, int) = nullptr;
    ptr_func = func;        //함수임
    result = ptr_func(value_a, value_b);
    std::cout << result << std::endl;
    std::cout << func_pointer(func) << std::endl;
    std::cout << func_pointer(func2) << std::endl;
    //call back함수
}
int func(int param_a, int param_b)
{
    return param_a + param_b;
}

int func2(int param_a, int param_b)
{
    return param_a - param_b;
}

int func_pointer(int(*ptr_param)(int a, int b))
{
    int result = ptr_param(20'000 , 30'000);
    return result;

}
