
#include <iostream>


void show_array(int (*ptr_array)[4], int row, int colomn)    //(*ptr_array)[4] -- 4칸을 건너띄면 다음행이 나온다는 것을 알려줘야한다.// *ptr_array[4] 의 연산순위 : ptr_array[4] * -> 괄호로 묶어줘야함
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < colomn; ++j)
        {
            //std::cout << ptr_array[i][j] << "\t";
            std::cout << *(*(ptr_array + i) + j) << "\t";
        }
        std::cout << std::endl;
    }
}


int main()
{
    int data[3][4]{ {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    show_array(data, sizeof data / sizeof data[0] /*3*/, sizeof data[0] / sizeof data[0][0]/*4*/);    //data,12는 안된다 -> 1차원 배열로 인식한다.
}

