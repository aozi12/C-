
#include <iostream>

//char* buildstring(char ch, int times)
//{
//    char* ptr_str{ new char[times + 1] };
//    ptr_str[times] = '\0';  //index[10]에 '\0'을 넣음으로서, 문자열을 출력시키고, 종료할 수 있음.
//    while (times--) {               //while (10--, 9--, 8--) / ptr_str[9,8,7.....]
//        ptr_str[times] = ch;
//    }
//    //delete[] ptr_str; -> 포인터를 삭제시키면 메인 함수에서 주소를 받을 수 없다. (ptr_str의 주소값이 사라졌기 때문에, 리턴값이 없다.)
//    return ptr_str;
//}
//
//int main()
//{
//    char* ptr_str = buildstring('H', 10);   //buildstring함수에서 만들어진, 힙영역에 있는 가상메모리의 주소를 공유하면서 사용함
//
//    std::cout << ptr_str << std::endl;
//    for (int i = 0; i < 10; ++i) {
//        std::cout << ptr_str[i] << "\t";
//    }
//    std::cout << std::endl;
//
//    delete[] ptr_str;   //buildstring에 의해 만들어진 영역의 포인터를 해제시켜줘야한다.
//    ptr_str = buildstring('0', 20);
//    delete[] ptr_str;
//    ptr_str = nullptr;
//}

//함수와 구조체

typedef struct TravelTime {
    int hour;
    int minute;
}Travel_Time;

TravelTime sum(const struct TravelTime* time1, const struct TravelTime* time2)   //우물이다. 함수의 주소값을 던지면 볼 수 있게 된다.
{
    struct TravelTime _time;
    _time.hour = time1->hour + time2->hour;
    _time.minute = time1->minute + time2->minute;     //struct의 복사본이 만들어짐
    return _time;   //struct의 복사본을 반환함
}

Travel_Time sum2(Travel_Time* time1, Travel_Time* time2)
{
    Travel_Time _time;
    _time.hour = time1->hour + time2->hour;
    _time.minute = time1->minute + time2->minute;     //struct의 복사본이 만들어짐
    return _time;   //struct의 복사본을 반환함
}

int main()
{
    Travel_Time time1{ 10, 5 };
    Travel_Time time2{ 5, 50 };
    Travel_Time result = sum(&time1, &time2);
    //sum(time2, time1);
    std::cout << result.hour << "\t" << result.minute << std::endl;
    return 0;
}
