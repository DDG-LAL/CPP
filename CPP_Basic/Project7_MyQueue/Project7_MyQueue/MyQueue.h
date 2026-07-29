#pragma once

#include<iostream>
#include<deque>
using std::deque;

namespace MyQueue
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& data)
		{
			_con.push_back(data);
		}
		void pop()
		{
			_con.pop_front();
		}
		const T& back()
		{
			return _con.back();
		}
		const T& front()
		{
			return _con.front();
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