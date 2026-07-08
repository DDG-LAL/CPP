#define _CRT_SECURE_NO_WARNINGS 1
//【电话号码的字母组合】
//给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合，可以按任意顺序返回
//给出数字到字母的映射如下（与电话按键相同），其中1不对应任何字母
// 1 -       2 - abc   3 - def
// 4 - ghi   5 - jkl   6 - mno
// 7 - pqrs  8 - tuv   9 - wxyz
//
//示例1:
//输入: digits = "23"
//输出: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//
//示例2:
//输入: digits = "2"
//输出: ["a", "b", "c"]

#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution
{
	const char* num_str_arr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
public:
	void combine(const string& digits, int i, string combine_str, vector<string>& ret)
	{
		if (i == digits.size())
		{
			ret.push_back(combine_str);
			return;
		}
		int num = digits[i] - '0';
		string str = num_str_arr[num];
		for (auto ch : str)
			combine(digits, i + 1, combine_str + ch, ret); //递归
	}
	vector<string> letterCombinations(const string& digits)
	{
		vector<string> ret;
		if (digits.empty())
			return ret;
		string str;
		combine(digits, 0, str, ret);
		return ret;
	}
};

int main()
{
	vector<string> v = Solution().letterCombinations("236");
	int count = 0;
	for (auto e : v)
	{
		cout << e << " ";
		if (++count == 5)
		{
			count = 0;
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}