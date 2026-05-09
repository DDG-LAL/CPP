#define _CRT_SECURE_NO_WARNINGS 1
//【以k为单位反转字符串】
//给定一个字符串s、一个整数k，s只由小写英语字母组成
//从字符串开头计起，每计数至2k个字符，就反转这2k字符中的前k个字符，再重新计数
//若剩余字符少于k个，则将剩余字符全部反转
//若剩余字符小于2k个，但大于或等于k个，则反转前k个字符，其余字符保持原样

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::reverse;

class Solution
{
public:
	size_t min(size_t x, size_t y)
	{
		return x < y ? x : y;
	}
	string& reverseStr(string& s, int k)
	{
		size_t size = s.size();
		for (size_t i = 0; i < size; i += 2 * k)
			reverse(s.begin() + i, s.begin() + min(i + k, size)); 
		return s;
	}																						
};
//标准库的reverse函数，void reverse(iterator _first, iterator _last);
//参数是迭代器，并且是左闭右开区间
//例如：_first==0，_last==3，则被执行反转的数据下标为0, 1, 2

int main()
{
	string s = "abcdefgh";
	cout << s << endl << endl;
	Solution().reverseStr(s, 2); 
	cout << s << endl << endl; //bacdfegh

	s = "abcdefgh";
	Solution().reverseStr(s, 3);
	cout << s << endl << endl; //cbadefhg

	s = "abcdefgh";
	Solution().reverseStr(s, 4);
	cout << s << endl << endl; //dcbaefgh

	s = "abcdefgh";
	Solution().reverseStr(s, 5);
	cout << s << endl << endl; //edcbafgh

	return 0;
}