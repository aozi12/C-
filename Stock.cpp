#include "Stock.h"
void Stock::set_total()
{
    (*this).total_value = this->shares * this->share_value;
}
void Stock::acquire(const std::string& co, long n, double pr)
{
    if (n < 0) {
        std::cout << "주식은 음수가 될  수 없습니다." << std::endl;
        this->shares = 0;
        return;
    }
    this->shares = n;
    this->company = co;
    this->share_value = pr;
    this->set_total();
}
void Stock::buy(long num, double price)
{
    if (num < 0) {
        std::cout << "주식은 음수가 될 수 없습니다" << std::endl;
        return;
    }
    this->shares += num;
    this->share_value += price;
    this->set_total();
}
void Stock::sell(long num, double price)
{
    if (num < 0) {
        std::cout << "보유주식보다 많으면 안된다." << std::endl;
        return;
    }
    else {
        this->shares -= num;
        this->share_value = price;
        this->set_total();
    }
}
void Stock::update(double price)
{
    this->share_value = price;
    this->set_total();
}
void Stock::show()
{
    std::cout << "회사명 : " << this->company << std::endl;
    std::cout << "주식수 : " << this->shares << std::endl;
    std::cout << "주가 :  $" << this->share_value << std::endl;
    std::cout << "주식 총 가치 : " << this->total_value << std::endl;

}
Stock::Stock()
{//초기값 설정할 때 많이 쓴다.
    this->company = "";
    this->shares = 0L;
    this->share_value = 0;
    this->total_value = 0;
    std::cout << "내가만든 Default 생성자" << std::endl;
}

Stock::~Stock()
{
    std::cout << "난 소멸자" << std::endl;
}

Stock::Stock(/*this*/ std::string company, long number, double price)
{
    if (number < 0)
    {
        std::cout << "음수를 가질 수 없습니다." << std::endl;
        return;
    }
    this->shares = number;
    this->company = company;
    this->share_value = price;
}

const Stock& Stock::topvalue(const Stock& stock) const // =연산자금지
{
    if (stock.total_value > this->total_value)
    {
        return stock;
    }
    return *this; //그 주소로 가란말
}