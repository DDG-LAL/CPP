#define _CRT_SECURE_NO_WARNINGS 1

#include"MyStack.h"
using namespace MyStack;
using std::cout;

int main()
{
	MyStack::stack<int, vector<int>> st;
	st.push(9);
	st.push(6);
	st.push(3);
	st.push(1);
	st.push(0);

	cout << st.size() << endl;
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}