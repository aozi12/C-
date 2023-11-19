#include "Stock.h"
void Stock::set_total()
{
    (*this).total_value = this->shares * this->share_value;
}
void Stock::acquire(const std::string& co, long n, double pr)
{
    if (n < 0) {
        std::cout << "�ֽ��� ������ ��  �� �����ϴ�." << std::endl;
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
        std::cout << "�ֽ��� ������ �� �� �����ϴ�" << std::endl;
        return;
    }
    this->shares += num;
    this->share_value += price;
    this->set_total();
}
void Stock::sell(long num, double price)
{
    if (num < 0) {
        std::cout << "�����ֽĺ��� ������ �ȵȴ�." << std::endl;
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
    std::cout << "ȸ��� : " << this->company << std::endl;
    std::cout << "�ֽļ� : " << this->shares << std::endl;
    std::cout << "�ְ� :  $" << this->share_value << std::endl;
    std::cout << "�ֽ� �� ��ġ : " << this->total_value << std::endl;

}
Stock::Stock()
{//�ʱⰪ ������ �� ���� ����.
    this->company = "";
    this->shares = 0L;
    this->share_value = 0;
    this->total_value = 0;
    std::cout << "�������� Default ������" << std::endl;
}

Stock::~Stock()
{
    std::cout << "�� �Ҹ���" << std::endl;
}

Stock::Stock(/*this*/ std::string company, long number, double price)
{
    if (number < 0)
    {
        std::cout << "������ ���� �� �����ϴ�." << std::endl;
        return;
    }
    this->shares = number;
    this->company = company;
    this->share_value = price;
}

const Stock& Stock::topvalue(const Stock& stock) const // =�����ڱ���
{
    if (stock.total_value > this->total_value)
    {
        return stock;
    }
    return *this; //�� �ּҷ� ������
}