#define _CRT_SECURE_NO_WARNINGS 1
//【仅反转字母】
//给定一个字符串s，要求执行以下操作：
//所有非英文字母保留在原有位置，所有英文字母位置反转(包括大小写)
//返回反转后的s
//
//示例1：
//输入：s = "ab-cd"
//输出："dc-ba"
//
//示例2：
//输入：s = "a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"

#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;

class Solution
{
public:
	bool isletter(char x)
	{
		return (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'));
	}
	string reverseOnlyLetters(string s)
	{
		int size = s.size();
		int l = 0, r = s.size() - 1;
		while (l < r)
		{
			while (l < r && !isletter(s[l])) //先检查后访问
				++l;
			while (l < r && !isletter(s[r]))
				--r;
			swap(s[l], s[r]);
			++l;
			--r;
		}
		return s;
	}
};

int main()
{
	string s = "aaAAbc123 0xyz-,QQwerr;'";
	cout << s << endl;
	cout << Solution().reverseOnlyLetters(s) << endl;
	return 0;
}