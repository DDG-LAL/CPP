#define _CRT_SECURE_NO_WARNINGS 1
//【最小栈】
//实现一个支持push，pop，top操作，并能在常数时间内检索到最小元素的栈MinStack
//MinStack类:
//MinStack() 初始化堆栈对象
//void push(int value) 将元素value推入堆栈
//void pop() 删除堆栈顶部的元素
//int top() 获取堆栈顶部的元素
//int getMin() 获取堆栈中的最小元素

#include<iostream>
#include<stack>
using std::stack;
using std::endl;
using std::cout;

class MinStack
{
public:
	void push(int value)
	{
		_data.push(value);
		if (_min.empty() || value <= _min.top())
			_min.push(value);
	}

	void pop()
	{
		if (_data.top() == _min.top())
			_min.pop();
		_data.pop();
	}

	int top() { return _data.top(); }

	int getMin() { return _min.top(); }
private:
	stack<int> _data;
	stack<int> _min;
};


int main()
{
	MinStack s;
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(3);
	s.push(5);
	s.push(9);
	s.push(3);
	s.push(3);
	cout << s.getMin() << endl; //3
	s.pop();
	cout << s.getMin() << endl; //3
	s.pop();
	cout << s.getMin() << endl; //3
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	cout << s.getMin() << endl; //5

	return 0;
}