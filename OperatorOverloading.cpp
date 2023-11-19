// OperatorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
class Time {
	
	int hour;
	int minute;
public:
	explicit Time() {
		this->hour = 0;
		this->minute = 0;
		std::cout << "Time() 생성자 호출" << std::endl;
	} //Default 형인 생성자
	~Time() {
		std::cout <<  "~Time() 소멸자 호출" << std::endl;
	}//소멸자
	Time(int hour, int minute)
	{
		this->hour = hour;
		this->minute = minute;
		std::cout << "Time() 생성자 호출" << std::endl;
	}
	void addMinute(int minute)
	{
		this->minute += minute;
		this->hour += static_cast<int>(minute / 60);
		this->minute %= 60;
	}
	void addHour(int hour)
	{
		this->hour += hour;

	}

	void reset(int hour = 0, int minute = 0)
	{
		this->minute = minute;
		this->hour = hour;
	}

	Time sum(const Time& time) const
	{
		Time _time = Time();
		_time.minute = this->minute + time.minute;
		_time.hour = this->hour + time.hour + (int)_time.minute / 60;
		_time.minute %= 60;
		return _time;
	}
	Time operator+(const Time& time)
	{
		Time _time = Time();
		_time.minute = this->minute + time.minute;
		_time.hour = this->hour + time.hour + (int)_time.minute / 60;
		_time.minute %= 60;
		return _time;
	}
	Time operator-(const Time& time) const {
		Time _time = Time();
		int total__time_minute = this->minute + this->hour * 60;
		int total_time_minute = time.minute + time.hour * 60;
		_time.minute = this->minute + time.minute;
		_time.hour = this->hour + time.hour + (int)_time.minute / 60;
		_time.minute %= 60;
		return _time;
	}
	void show() const
	{
		std::cout << this->hour << "시간\t" << this->minute << " 분" << std::endl;
	}
};
int main()
{
	Time time{Time()};
	Time time1(1, 10);
	Time time2(3, 50);
	time1.addHour(2);
	time1.show();
	//time = time1.sum(time2);
	//time = time1.operator+(time2);
	time = time1 + time2; //연산자 오버로딩
	time.show();

}

