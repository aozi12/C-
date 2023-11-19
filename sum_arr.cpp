////좀더 공부가 필요함.
//
#include <iostream>
//
////int sum_arr(int arr[]/*== *arr */, int n);
//
//void show_oldstyle_array(const int[]);		//소비형 -> 오로지, 배열의 값을 보여주기 위한 함수
//void show_newstyle_array(const int[]);
//
//int main()
//{
//	int array1[]{ 1, 2, 3, 4, 5, 6, 7 };
//	int array2[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	
//	//for (int i = 0; i < sizeof array1 / sizeof array1[0]; ++i)	//magic code -> 배열의 갯수가 바뀌면 조건의 상수값을 변경해줘야 하는 코드(i < 7)
//	//{
//	//	std::cout << array1[i] << "\t";
//	//}
//	//
//	//for (int i = 0; i < sizeof array2 / sizeof array2[0]; ++i) //magic code -> general code <sizeof array1 / sizeof array1[0];>
//	//{
//	//	std::cout << array2[i] << "\t";
//	//}
//
//	//std::cout << std::endl;
//	
//	show_oldstyle_array(array1);
//	show_newstyle_array(array2, (sizeof array2 / sizeof array2[0]));
//}
//
//void show_oldstyle_array(const int param[])
//{
//	for (int i = 0; i < sizeof param / sizeof param[0]; ++i)	//sizeof param은 배열의 첫번째 주소값을 받는다 8byte
//	{
//		std::cout << param[i] << "\t";
//	}
//	std::cout << std::endl;
//}
//
//void show_newstyle_array(const int param[], const int size)
//{
//	for (int i = 0; i <size; ++i)	//sizeof param은 배열의 첫번째 주소값을 받는다 8byte
//	{
//		std::cout << param[i] << "\t";
//	}
//	std::cout << std::endl;
//}






void show_oldstyle_array(const int[]);    //소비형함수
void show_newstyle_array(const int[], const int);

int main()
{
    int array1[]{ 1, 2, 3, 4, 5, 6, 7 };
    int array2[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    //for (int i = 0; i < 7; ++i)     // magic code : 사이즈를 맞춰서 7로 쓴것
    for (int i = 0; i < sizeof array1 / sizeof array1[0]; ++i)  // sizeof 함수를 쓰면 총바이트/1개의 바이트 로 자동적으로 갯수가 구해짐
    {
        std::cout << array1[i] << "\t";
    }
    std::cout << std::endl;

    for (int i = 0; i < 9; ++i)
    {
        std::cout << array2[i] << "\t";
    }
    std::cout << std::endl;

    show_oldstyle_array(array1);
    show_oldstyle_array(array2);
    show_newstyle_array(array1, (sizeof array1 / sizeof array1[0]));
    show_newstyle_array(array2, (sizeof array2 / sizeof array2[0]));

}

void show_oldstyle_array(const int param[])          
{
    for (int i = 0; i < sizeof param / sizeof param[0]; ++i)    //sizeof param은 배열의 첫번째 주소값을 받는다 8byte / param[0] = 4byte --> 2byte라서, 제대로 실행이 안됨.
    {
        std::cout << param[i] << "\t";
    }
    std::cout << std::endl;
}

void show_newstyle_array(const int param[], const int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << param[i] << "\t";
    }
    std::cout << std::endl;
}