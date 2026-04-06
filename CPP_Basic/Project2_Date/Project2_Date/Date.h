#pragma once

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1); //构造函数
	Date(const Date& src); //拷贝构造函数
	void print() const; //const修饰this指针
	//意思是void print(const Date* this);

	int GetMonthDay(int year, int month); //获取当月天数

	bool operator<(const Date& d); //运算符重载函数
	bool operator==(const Date& d);
	bool operator>(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	Date& operator++(); //前置++
	Date operator++(int); //后置++，参数int只是为了构成重载，区分前置后置，没有其它作用
	Date& operator--(); //前置--
	Date operator--(int); //后置--

	Date& operator=(const Date& d); //赋值重载函数

	int operator-(const Date& d); //日期相减

	//~Date(); //析构函数
private:
	int _year;
	int _month;
	int _day;
};