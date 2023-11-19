// ProblemSTRING.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
//int StringBad::number_string {0 };
class StringBad
{
private:
    char* str;
    int length;
    static int number_object;
public:
    int get_length()
    {
        std::cout << this->number_object << std::endl;
        StringBad::get_numbers_string;
        return this->length;
    }

    static int get_numbers_string() 
        //static 함수는 this가 없어서 인스턴스변수에 접근할 수 없다.
        //static변수에만 접근할 수 있다.
    {
        
        //StringBad::number_object = 100;
        
        return StringBad::number_object;
    }
    StringBad()
    {
        this->str = new char[BUFSIZ];
        this->length = BUFSIZ;
       // StringBad::number_object = 0;
        StringBad::number_object++;
        std::cout << "객체 갯수 : " << StringBad::number_object << std::endl;
    }
    StringBad(const char* str)
    {
        this->length = (int)std::strlen(str);
        this->str = new char[length + 1];   //'\0'
        strcpy_s(this->str, length + 1, str);
        StringBad::number_object++;//++
        std::cout << "객체 갯수 : " << StringBad::number_object << std::endl;
        std::cout << this->str << std::endl;
    }
    StringBad& operator = (const StringBad& rhs)
    {
        std::cout << "Assigment operator called" << std::endl;
        delete[] this->str;
        this->length = rhs.length;
        this->str = new char[length + 1];
        strcpy_s(this->str, length + 1)
        return *this;
    }
    ~StringBad()
    {
        
        //StringBad::number_object = 0;
        StringBad::number_object--;//++
        std::cout << "객체 갯수 : " << StringBad::number_object << std::endl;
        delete[]this->str;
        this->length = 0;
        this->str = nullptr;
    }
    friend std::ostream& operator<<(std::ostream& os, const StringBad& rhs);
};

std::ostream& operator<<(std::ostream& os, const StringBad& rhs)
{
    os << rhs;
    return os;
}
int StringBad::number_object {0};
int main()
{
    StringBad str1 = StringBad("Hello world");

    //StringBad str2 = StringBad(str1);
    StringBad str2(str1);
    StringBad str3 = "Android";
    str3 = str2;
    return 0;
    /*for (int i = 0; i < 10; ++i)
    {
        StringBad string_bad = StringBad();
        std::cout << string_bad << std::endl;
    }
    StringBad str1 = StringBad("Hello world");*/

    //StringBad string_bad = StringBad("Hello World");
   // std::cout << string_bad << std::endl;
   
    //StringBad::get_numbers_string();
    //string_bad.length = 10;
   // StringBad::number_string = 10;
   
  //  std::cout << StringBad::get_numbers_string() << std::endl;

}
