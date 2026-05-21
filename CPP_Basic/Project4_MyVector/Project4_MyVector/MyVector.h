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
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector() //无参构造
			//: _start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{}
		vector(const vector<T>& v) //拷贝构造
			//: _start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (auto& e : v)
				push_back(e);
		}
		vector(size_t n, const T& val = T()) //用给定数量的相同对象进行构造
			//: _start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
				push_back(val);
		}
		vector(int n, const T& val = T()) //用给定数量的相同对象进行构造
			//: _start(nullptr)			  //为了避免参数是(int, int)时调用模板，重载给出更匹配的函数
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
				push_back(val);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last) //迭代器区间构造
			//: _start(nullptr)
			//, _finish(nullptr)
			//, _end_of_storage(nullptr)
		{
			while (first != last)
				push_back(*first++);
		}
		vector<T>& operator=(vector<T> tmp) //赋值重载
		{
			swap(tmp);
			return *this;
		}
		~vector() //析构
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		void reserve(size_t newcapacity) //修改容量
		{
			if (newcapacity > capacity())
			{
				size_t sz = size();
				T* tmp = new T[newcapacity];
				if (_start != nullptr)
				{
					//memcpy(tmp, _start, sizeof(T) * sz); //存在浅拷贝问题
					for (size_t i = 0; i < sz; ++i)
						tmp[i] = _start[i]; //利用赋值重载进行深拷贝
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + sz; //指针_finish更新
				_end_of_storage = _start + newcapacity; //指针_end_of_storage更新
			}
		}
		void resize(size_t newsize, const T& val = T()) //修改长度
		{							//缺省值使用匿名对象，内置类型也有默认构造函数，也可以正常使用
			if (newsize <= size())
				_finish = _start + newsize;
			else
			{
				reserve(newsize);
				while (_finish < _start + newsize)
					*_finish++ = val;
			}
		}

		void push_back(const T& val) //尾插
		{
			//if (_finish == _end_of_storage)
			//{
			//	size_t cap = capacity();
			//	reserve(cap == 0 ? 4 : cap * 2);
			//}
			//*_finish = val;
			//++_finish;
			insert(_finish, val);
		}
		void pop_back() //尾删
		{
			if (_finish != _start)
				--_finish;
		}

		void insert(iterator pos, const T& val) //在pos的前一个位置插入
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			if (_finish == _end_of_storage)
			{
				size_t cap = capacity(), len = pos - _start; //扩容后_start转移，导致pos失效，因此预先记录pos
				reserve(cap == 0 ? 4 : cap * 2);
				pos = _start + len; //扩容后_start转移，导致pos失效，因此更新pos
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
		}
		iterator erase(iterator pos) //删除pos位置数据
		{
			assert(pos < _finish);
			assert(pos >= _start);
			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos; //返回pos位置，用于解决迭代器失效
		}

		void clear()
		{
			_finish = _start;
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
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}
