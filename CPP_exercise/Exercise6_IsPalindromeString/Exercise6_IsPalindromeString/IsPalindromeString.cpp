#define _CRT_SECURE_NO_WARNINGS 1
//【验证回文串】
//回文串：将所有大写字母字符转换为小写字母字符并移除所有非字母数字字符之后，正着读和反着读都一样的字符串
//给出一个字符串s，若它是回文串，返回true，否则返回false

#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

class Solution
{
public:
	bool is_letter_or_number(char c)
	{
		return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'));
	}
	void capital_letter(char& c)
	{
		if ('A' <= c && c <= 'Z')
			c = c - ('A' - 'a');
	}
	bool isPalindrome(string s)
	{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			while (left < right && !is_letter_or_number(s[left]))
				++left;
			capital_letter(s[left]);
			while (left < right && !is_letter_or_number(s[right]))
				--right;
			capital_letter(s[right]);
			if (s[left] == s[right])
			{
				++left;
				--right;
			}
			else
				return false;
		}
		return true;
	}
};

int main()
{
	string s;
	getline(cin, s);
	cout << ((Solution().isPalindrome(s) == 0) ? "false" : "true") << endl;
	return 0;
}