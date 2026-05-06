#pragma once
#include<iostream>
#include<assert.h>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

namespace MyString
{
	class string
	{
	public:
		//string() //无参构造
		//	: _str(new char[1]{ '\0' })
		//	, _size(0)
		//	, _capacity(0)
		//{}
		string(const char* str = "") //全缺省构造
			: _size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		~string() //析构
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}
		size_t size() const //返回字符串长度
		{
			return _size;
		}
		size_t capacity() const //返回容量
		{
			return _capacity;
		}

		//方括号运算符重载
		char& operator[](size_t pos) //可读写，用于普通对象
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const //只读，用于const对象
		{
			assert(pos < _size);
			return _str[pos];
		}

		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		typedef const char* const_iterator;
		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		void reserve(size_t newcapacity) //修改容量
		{
			if (newcapacity > _capacity)
			{
				char* tmp = new char[newcapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newcapacity;
			}
		}
		void push_back(const char c) //尾插单个字符
		{
			if (_size == _capacity)
				reserve(_capacity == 0 ? 2 : _capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void append(const char* str) //尾插字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const char c) //重载+=，尾插单个字符
		{
			push_back(c);
			return *this;
		}
		string& operator+=(const char* str) //重载+=，尾插字符串
		{
			append(str);
			return *this;
		}
		string operator+(const char c) //重载+，用于单个字符
		{
			string tmp(_str);
			tmp += c;
			return tmp;
		}
		string operator+(const char* str) //重载+，用于字符串
		{
			string tmp(_str);
			tmp += str;
			return tmp;
		}

		void insert(size_t pos, const char c) //插入单个字符
		{
			if (_size == _capacity)
				reserve(_capacity == 0 ? 2 : _capacity * 2);
			size_t end = _size + 1;
			while (pos < end)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = c;
			++_size;
		}
		void insert(size_t pos, const char* str) //插入字符串
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);
			size_t end = _size + len;
			while (pos + len - 1 < end)
			{
				_str[end] = _str[end - len];
				--end;
			}
			int i = 0;
			while (str[i] != '\0')
				_str[pos++] = str[i++];
			_size += len;
		}
		void erase(size_t pos, size_t len = npos) //清除字符串
		{
			if (len == npos || pos + len > _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//比较运算符重载
		bool operator<(const string& s)const
		{
			return strcmp(_str, s._str) < 0;
		}
		bool operator==(const string& s)const
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator>(const string& s)const
		{
			return !(*this < s || *this == s);
		}
		bool operator<=(const string& s)const
		{
			return !(*this > s);
		}
		bool operator>=(const string& s)const
		{
			return !(*this < s);
		}
		bool operator!=(const string& s)const
		{
			return !(*this == s);
		}



		
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos;

		//const static size_t npos = -1; 
		//只有const静态整型变量可以这样给缺省值，其它的静态成员变量不可以
	};
	const size_t string::npos = -1;


	//流插入运算符重载
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
			out << ch;
		return out;
	}
	//流提取运算符重载
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char c;
		//in >> c; //无法提取' '和'\n'
		c = in.get();
		while (c != ' ' && c != '\n')
		{
			s += c;
			//in >> c;
			c = in.get();
		}
		return in;
	}
}
