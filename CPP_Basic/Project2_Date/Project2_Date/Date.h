#pragma once

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d); //友元声明
	friend istream& operator>>(istream& in, Date& d); //友元声明
public:
	Date(int year = 1, int month = 1, int day = 1); //构造函数
	Date(const Date& src); //拷贝构造函数
	void print() const; //const修饰*this
	//意思是void print(const Date* this);

	int GetMonthDay(int year, int month); //获取当月天数

	bool operator<(const Date& d) const; //运算符重载函数
	bool operator==(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator+=(int day);
	Date operator+(int day) const;

	Date& operator-=(int day);
	Date operator-(int day) const;

	Date& operator++(); //前置++
	Date operator++(int); //后置++，参数int只是为了构成重载，区分前置后置，没有其它作用
	Date& operator--(); //前置--
	Date operator--(int); //后置--

	Date& operator=(const Date& d); //赋值重载函数

	int operator-(const Date& d) const; //日期相减

	//Date* operator&(); //普通对象调用
	//const Date* operator&() const; //const对象调用
	//~Date(); //析构函数
private:
	int _year = 0; //初始化列表缺省值
	int _month = 0;
	int _day = 0;
};