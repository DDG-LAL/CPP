#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

Date::Date(int year, int month, int day) //构造函数
	: _year(year) //初始化列表
	, _month(month)
	, _day(day)
{
	if (month < 1 || month > 12 || day < 1 || day > GetMonthDay(year, month))
		cout << "非法日期" << endl;
}

Date::Date(const Date& src) //拷贝构造函数
{
	_year = src._year;
	_month = src._month;
	_day = src._day;
}

void Date::print() const //const修饰this指针
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

int Date::GetMonthDay(int year, int month) //获取当月天数
{
	const static int dayarr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2)
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return 29;
	return dayarr[month];
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;
	else
		return false;
}
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Date::operator>(const Date& d) const
{
	return !((*this < d) || (*this == d));
}
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += (-day);
	_day -= day;
	while (_day < 1)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator++() //前置++
{
	*this += 1;
	return *this;
}
Date Date::operator++(int) //后置++
{
	Date ret = *this;
	*this += 1;
	return ret;
}
Date& Date::operator--() //前置--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int) //后置--
{
	Date ret = *this;
	*this -= 1;
	return ret;
}

Date& Date::operator=(const Date& d) //赋值重载函数
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

int Date::operator-(const Date& d) const //日期相减
{
	Date begin = d;
	Date end = *this;
	int flag = 1;
	if (*this < d)
	{
		begin = *this;
		end = d;
		flag = -1;
	}
	int count = 0;
	while (begin != end)
	{
		++begin;
		++count;
	}
	return count * flag;
}

//Date* Date::operator&() //普通对象调用
//{
//	return this;
//}
//const Date* Date::operator&() const //const对象调用
//{
//	return this;
//}
//Date::~Date() //析构函数
//{
//	cout << "析构" << endl;
//}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}