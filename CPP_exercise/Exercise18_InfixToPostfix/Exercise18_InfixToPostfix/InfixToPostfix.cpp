#define _CRT_SECURE_NO_WARNINGS 1
//【中缀表达式转化为后缀表达式】
//给出一个中缀表达式，要求输出一个后缀表达式
//表达式只包含"+"、"-"、"*"、"/"、"("、")"以及整数
//以字符串形式输出

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::stack;
using std::cout;
using std::endl;

class Solution
{
private:
	int GetPriority(const string& str) //判断优先级
	{
		if (str == "+" || str == "-") return 1;
		if (str == "*" || str == "/") return 2;
		return -1;
	}

	string convert(vector<string>& tokens, int& i)
	{
		stack<string> st;
		string ret;
		while (size_t(i) < tokens.size())
		{
			const string& str = tokens[i];
			if (str == "(")
			{
				++i; //越过左括号
				if (!ret.empty()) ret += " ";
				ret += convert(tokens, i); //递归处理
			}
			else if (str == ")")
			{
				while (!st.empty())
				{
					if (!ret.empty()) ret += " ";
					ret += st.top(); //将括号内处理完成的表达式写入ret
					st.pop();
				}
				return ret; //返回子表达式结果，此时i仍然指向右括号，在大循环末尾再进行迭代
			}
			else if (str == "+" || str == "-" || str == "*" || str == "/") //当前元素为运算符
			{
				if (st.empty() || GetPriority(st.top()) < GetPriority(str))
					st.push(str); //若栈为空，或当前运算符优先级高于栈顶运算符，则入栈
				else //若当前运算符优先级等于或低于栈顶运算符，则将栈顶元素写入ret并出栈，当前运算符再次与栈顶元素比较
				{
					while (!st.empty() && GetPriority(st.top()) >= GetPriority(str))
					{
						if (!ret.empty()) ret += " ";
						ret += st.top();
						st.pop();
					}
					st.push(str);
				}
			}
			else
			{
				if (!ret.empty()) ret += " ";
				ret += str; //当前元素不是运算符，则写入ret
			}
			++i; //迭代
		}
		while (!st.empty()) //将栈内剩余的运算符写入ret
		{
			if (!ret.empty()) ret += " ";
			ret += st.top();
			st.pop();
		}
		return ret;
	}
public:
	string InfixToPostfix(vector<string>& tokens)
	{
		int i = 0;
		return convert(tokens, i);
	}
};

int main()
{
	vector<string> test = { "10", "*", "(", "6", "/", "(", "(", "9", "+", "3", ")", "*", "-11", ")", ")", "+", "17" };
	int i = 0;
	for (auto e : test)
		cout << e << " ";
	cout << endl << endl;
	cout << (Solution().InfixToPostfix(test)) << endl;

	return 0;
}