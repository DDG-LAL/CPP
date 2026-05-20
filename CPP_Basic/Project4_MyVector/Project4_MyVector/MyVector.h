#pragma once
#include<iostream>
#include<assert.h>
using std::cout;
using std::endl;

namespace MyVector
{
	template<class T>
	class vector
	{
	public:
		//typedef T value_type;
		//typedef value_type* iterator;
		//typedef const value_type* const_iterator;
		//iterator start;
		//iterator finish;
		//iterator end_of_storage;
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		vector() //无参构造
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		~vector() //析构
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}

		void push_back(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				size_t cap = capacity(), sz = size();
				size_t newcapacity = cap == 0 ? 4 : cap * 2;
				T* tmp = new T[newcapacity];
				if (_start != nullptr)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz; //指针_finish更新
				_end_of_storage = _start + newcapacity; //指针_end_of_storage更新
			}
			*_finish = val;
			++_finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return *(_start + pos);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}
