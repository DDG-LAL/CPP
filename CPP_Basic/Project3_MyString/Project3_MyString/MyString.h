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
		//string(const string& s) //拷贝构造(传统写法)
		//	: _size(s._size)
		//	, _capacity(s._capacity)
		//{
		//	_str = new char[_capacity + 1];
		//	strcpy(_str, s._str);
		//}
		string(const string& s) //拷贝构造(现代写法)
			: _str(nullptr) //初始化，防止与tmp交换后tmp析构出错
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		//string& operator=(const string& s) //赋值重载(传统写法)
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp; //根据s._str的长度直接修改this->_str的长度，减少空间消耗
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	//if (this != &s) //直接reserve
		//	//{				  //如果*this的字符串长度远大于s，则出现空间浪费
		//	//	clear();
		//	//	reserve(s._size); 
		//	//	*this += s._str;
		//	//}
		//	return *this;
		//}
		//string& operator=(const string& s) //赋值重载(现代写法)
		//{
		//	if (this != &s)
		//	{
		//		//string tmp(s._str); 
		//		//直接构造，不用拷贝构造，简洁，少一次初始化、少一次swap、少一次析构
		// 
		//		string tmp(s); 
		//		//便于维护，如果修改拷贝构造的逻辑也不受影响
		// 
		//		swap(tmp);
		//	}
		//	return *this;
		//}
		string& operator=(string tmp) //赋值重载(更短的现代写法)
		{
			swap(tmp); //tmp传值传参，已经是一个拷贝，然后再与*this进行swap
			return *this;
		} //不需要写if (this != &s)，因为传参时已经发生了拷贝构造，在if之前已经发生了主要的消耗

		void swap(string& s) //交换
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
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

		void resize(size_t newsize, const char c = '\0') //修改字符串长度
		{
			if (newsize <= _size)
			{
				_str[newsize] = '\0';
				_size = newsize;
			}
			else
			{
				reserve(newsize);
				//size_t pos = newsize - 1;
				//while (pos >= _size)
				//	_str[pos--] = c;
				//_str[newsize] = '\0';
				//_size = newsize;
				while (_size < newsize)
					_str[_size++] = c;
				_str[_size] = '\0';
			}
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
			assert(pos <= _size);
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
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);
			size_t end = _size + len;
			while (pos + len - 1 < end)
			{
				_str[end] = _str[end - len];
				--end;
			}
			//size_t i = 0;
			//while (str[i] != '\0')
			//	_str[pos++] = str[i++];
			strncpy(_str + pos, str, len);
			_size += len;
		}
		void erase(size_t pos, size_t len = npos) //清除字符串
		{
			assert(pos <= _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//size_t begin = pos + len;
				//while (begin <= _size)
				//{
				//	_str[begin - len] = _str[begin];
				//	++begin;
				//}
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

		size_t find(const char c, size_t pos = 0)const //查找单个字符
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; ++i)
				if (_str[i] == c)
					return i;
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0) const //查找字符串
		{
			assert(pos < _size);
			const char* psub = strstr(_str + pos, sub);
			if (psub)
				return (size_t)(psub - _str);
			else
				return npos;
		}

		string substr(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			string ret;
			size_t end = pos + len;
			if (len == npos || pos + len > _size)
			{
				len = _size - pos;
				end = _size;
			}
			ret.reserve(len);
			for (size_t i = pos; i < end; ++i)
				ret += _str[i];
			//if (len == npos || pos + len > _size)
			//{
			//	ret.reserve(_size - pos);
			//	for (size_t i = pos; i < _size; ++i)
			//		ret += _str[i];
			//	//char* str = _str + pos; //如果有'\0'会读取不到
			//	//ret += str;
			//}
			//else
			//{
			//	ret.reserve(len);
			//	for (size_t i = pos; i < pos + len; ++i)
			//		ret += _str[i];
			//}
			return ret;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
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
	//istream& operator>>(istream& in, string& s)
	//{
	//	s.clear();
	//	char c;
	//	//in >> c; //无法提取' '和'\n'
	//	c = in.get();
	//	while (c != ' ' && c != '\n')
	//	{
	//		s += c;
	//		//in >> c;
	//		c = in.get();
	//	}
	//	return in;
	//}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char buf[129];
		size_t i = 0;
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buf[i++] = ch;
			if (i == 128) //使用buf优化，减少扩容次数
			{
				buf[i] = '\0';
				s += buf;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buf[i] = '\0';
			s += buf;
		}
		return in;
	}

	void test_my_string()
	{
		string website = "https://legacy.cplusplus.com/reference/string/string/?kw=string";
		string sub1, sub2, sub3;
		size_t i1 = website.find(':'); //查找第一个':'
		if (i1 != string::npos)
			sub1 = website.substr(0, i1); //提取协议，"https"
		size_t i2 = website.find('/', i1 + 3); //查找"https://"后的第一个'/'
		if (i2 != string::npos)
			sub2 = website.substr(i1 + 3, i2 - i1 - 3); //提取域名，"legacy.cplusplus.com"
		sub3 = website.substr(i2 + 1); //提取资源名，"reference/string/string/?kw=string"
		cout << endl << endl;
		cout << "  网站: " << website << endl;
		cout << "  协议: " << sub1 << endl;
		cout << "  域名: " << sub2 << endl;
		cout << "资源名: " << sub3 << endl;
	}
}
