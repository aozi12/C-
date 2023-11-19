// OLDSTYLE_CLASS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <cstdio>
int (*ptr_get)() = nullptr;
void (*ptr_set)(int) = nullptr;
struct MyData {
	int value;
	double money;
	/*int value;
	double money;*/
	ptr_get = get_value;
	ptr_set = set_value;
};
class Class_Data {
	int value;
	int get_value() {
		return value;
	}
	void set_value(int _value)
	{
		value = _value;
	}
};
int get_value()
{
	MyData data;
	return data.value;
}
void set_value(int _value)
{
	value = value;
}

	int get_money()
	{
		return money;
	}
	void set_money(double _money)
	{
		money = _money;
	}

int main()
{
	int value = 10;
	class Class_Data data;
		return 0;
}

