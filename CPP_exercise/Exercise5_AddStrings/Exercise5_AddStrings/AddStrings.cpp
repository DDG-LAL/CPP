#define _CRT_SECURE_NO_WARNINGS 1
//【字符串相加】
//给定两个字符串形式的非负整数num1和num2，计算它们的和并以字符串形式返回
//不允许使用任何內建的用于处理大整数的库(比如BigInteger)
//不允许直接将输入的字符串转换为整数形式

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::reverse;

class Solution
{
public:
	string addStrings(string& num1, string& num2)
	{
		string str;
		int i1 = num1.size() - 1;
		int i2 = num2.size() - 1;
		int next = 0;
		while (i1 >= 0 || i2 >= 0)
		{
			int n1 = i1 >= 0 ? (num1[i1] - '0') : 0; //确定当前位的数值
			int n2 = i2 >= 0 ? (num2[i2] - '0') : 0;
			int sum = n1 + n2 + next; //求当前位相加后的值
			next = sum / 10; //求进位

			//str.insert(0, 1, '0' + ret); //用insert头插，效率低

			//str.push_back('0' + (sum % 10)); //将当前位相加所得的个位尾插
			str += ('0' + (sum % 10)); //将当前位相加所得的个位尾插

			--i1; //迭代到下一位
			--i2;
		}
		if (next > 0)
			str.push_back('0' + next);
		reverse(str.begin(), str.end()); //逆置
		return str;
	}
};

int main()
{
	string s1("156756486");
	string s2("97406384266");
	cout << s1 << '+' << s2 << '=' << endl << endl;
	cout << Solution().addStrings(s1, s2) << endl; //97563140752
	return 0;
}