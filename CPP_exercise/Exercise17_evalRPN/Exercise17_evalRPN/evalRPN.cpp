#define _CRT_SECURE_NO_WARNINGS 1
//【逆波兰表达式求值】
//逆波兰表达式即后缀表达式
//给出一个字符串数组tokens
//tokens是一个根据逆波兰表示法表示的算术表达式
//计算该表达式，返回一个表示表达式值的整数

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::stack;
using std::cout;
using std::endl;
using std::stoi;

class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		for (auto e : tokens)
		{
			if (e == "+" || e == "-" || e == "*" || e == "/") //若当前元素是运算符，则取出栈顶两个元素进行运算，并将运算结果入栈
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				switch (e[0])
				{
				case '+':
					st.push(left + right);
					break;
				case '-':
					st.push(left - right);
					break;
				case '*':
					st.push(left * right);
					break;
				case '/':
					st.push(left / right);
					break;
				}
			}
			else
				st.push(stoi(e)); //若当前元素是数字，则入栈
		}
		return st.top();
	}
};

int main()
{
	vector<string> v = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	cout << (Solution().evalRPN(v)) << endl; //22

	return 0;
}