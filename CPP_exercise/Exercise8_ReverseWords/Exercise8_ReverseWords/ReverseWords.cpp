#define _CRT_SECURE_NO_WARNINGS 1
//【反转字符串中的单词】
//给定一个字符串s，要求反转字符串中每个单词的字符顺序，同时保留空格和单词的初始顺序
//s包含可打印的ASCII字符
//s中不包含开头或结尾空格，且至少有一个词
//s中所有单词都用一个空格隔开

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::reverse;

class Solution
{
public:
	string& reverseWords(string& s)
	{
		size_t left = 0, right = s.find(' ');
		size_t size = s.size();
		while (right != string::npos)
		{
			reverse(s.begin() + left, s.begin() + right);
			left = right + 1;
			right = s.find(' ', left);
		}
		reverse(s.begin() + left, s.end());
		return s;
	}
};

int main()
{
	string s("Let's take LeetCode contest");
	cout << s << endl;
	cout << Solution().reverseWords(s) << endl << endl;
	s = "illu sion";
	cout << s << endl;
	cout << Solution().reverseWords(s) << endl << endl;
	s = "";
	cout << s << endl;
	cout << Solution().reverseWords(s) << endl << endl;
	s = "a";
	cout << s << endl;
	cout << Solution().reverseWords(s) << endl << endl;

	return 0;
}