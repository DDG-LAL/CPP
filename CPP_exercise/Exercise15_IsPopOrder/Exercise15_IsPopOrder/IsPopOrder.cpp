#define _CRT_SECURE_NO_WARNINGS 1
//【栈的压入弹出序列】
//输入两个整数序列，第一个序列表示栈的压入顺序
//判断第二个序列是否可能为该栈的弹出顺序
//压入栈的所有数字均不相等
// 
// 0 <= pushV.length == popV.length <= 1000
// - 1000 <= pushV[i] <= 1000
// pushV 的所有数字均不相同

#include<iostream>
#include<stack>
#include<vector>
using std::vector;
using std::stack;
using std::endl;
using std::cout;

class Solution
{
public:
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
	{
		auto push_it = pushV.begin();
		auto pop_it = popV.begin();
		stack<int> st;
		while (push_it != pushV.end() && pop_it != popV.end())
		{
			st.push(*push_it); //将push序列里的一个元素入栈
			++push_it;
			while (!st.empty() && st.top() == *pop_it) //若栈顶元素与pop序列当前元素相等，则出栈
			{
				st.pop();
				++pop_it;
			}
		}
		return st.empty();
	}
};

int main()
{
	vector<int> push0 = { 1,3,2,5,4 };
	vector<int> pop0 = { 2,3,1,5,4 };
	cout << (Solution().IsPopOrder(push0, pop0) == true ? "true" : "false") << endl << endl; //true
	vector<int> push1 = { 1,3,2,5,4,6 };
	vector<int> pop1 = { 6,3,1,4,2,5 };
	cout << (Solution().IsPopOrder(push1, pop1) == true ? "true" : "false") << endl << endl; //false
	return 0;
}