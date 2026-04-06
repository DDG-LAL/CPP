#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using std::cin;
using std::cout;
using std::endl;

typedef int STdatatype;

class Stack
{
public:

	Stack(size_t size = 4) //构造函数
	{
		//cout << "构造\n" << endl;
		if (size == 0)
		{
			_data = nullptr;
			_top = _cap = 0;
		}
		else
		{
			STdatatype* tmp = (STdatatype*)malloc(sizeof(STdatatype) * size);
			if (tmp == nullptr)
			{
				perror("malloc\n");
				exit(-1);
			}
			_data = tmp;
			_top = 0;
			_cap = size;
		}
	}

	Stack(const Stack& s) //拷贝构造函数
	{
		_top = s._top;
		_cap = s._cap;
		STdatatype* tmp = (STdatatype*)malloc(sizeof(STdatatype) * s._cap);
		if(tmp==nullptr)
		{
			perror("malloc\n");
			exit(-1);
		}
		_data = tmp;
		memcpy(_data, s._data, sizeof(STdatatype) * s._cap);
	}

	bool Empty()
	{
		return 0 == _top;
	}

	void Push(STdatatype x)
	{
		if (_top == _cap)
		{
			size_t newcap = _cap == 0 ? 4 : _cap * 2;
			STdatatype* tmp = (STdatatype*)realloc(_data, sizeof(STdatatype) * newcap);
			if (tmp == nullptr)
			{
				perror("realloc\n");
				exit(-1);
			}
			_data = tmp;
			_cap = newcap;
		}
		_data[_top++] = x;
	}

	void Pop()
	{
		assert(!Empty());
		_top--;
	}

	STdatatype Top()
	{
		assert(!Empty());
		return _data[_top - 1];
	}

	int Size()
	{
		assert(_top >= 0);
		return _top;
	}

	~Stack() //析构函数
	{
		//cout << "\n析构\n" << endl;
		free(_data);
		//_data = nullptr;
		//_top = _cap = 0; //可以不写
	}

private:

	STdatatype* _data;
	int _top;
	int _cap;
};

int main()
{
	Stack st;
	st.Push(0);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Push(6);

	while (!st.Empty())
	{
		cout << st.Top() << " ";
		st.Pop();
	}
	cout << endl;

	return 0;
}