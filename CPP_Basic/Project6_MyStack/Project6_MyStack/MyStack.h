#pragma once

#include<iostream>
#include<deque>
using std::deque;
using std::endl;

namespace MyStack
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& data)
		{
			_con.push_back(data);
		}
		void pop()
		{
			_con.pop();
		}
		T top()
		{
			return _con.back();
		}
		void empty()
		{
			return _con.empty();
		}
		int size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}