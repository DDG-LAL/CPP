#pragma once

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
using std::vector;
using std::list;
using std::string;
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
			_con.pop_back();
		}
		const T& top()
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
	private:
		Container _con;
	};
}