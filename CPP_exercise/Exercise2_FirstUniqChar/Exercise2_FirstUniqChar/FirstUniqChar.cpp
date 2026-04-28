#define _CRT_SECURE_NO_WARNINGS 1
//【字符串第一个唯一字符】
//给定一个只包含小写字母的字符串s，找到它的第一个不重复的字符，并返回其下标
//若不存在，则返回-1

#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
	int firstUniqChar(string s)
	{
		int count[26] = { 0 };
		for (auto ch : s) //计数
			++count[ch - 'a'];

		for (size_t i = 0; i < s.size(); ++i) //遍历
			if (count[s[i] - 'a'] == 1)
				return i;
		return -1;
	}
};

int main()
{
	string s1 = "aabb";
	string s2 = "sstring";
	string s3 = "cpp";
	string s4 = "qqqweert";
	string s5 = "";
	cout << Solution().firstUniqChar(s1) << endl; //输出-1
	cout << Solution().firstUniqChar(s2) << endl; //输出2
	cout << Solution().firstUniqChar(s3) << endl; //输出0
	cout << Solution().firstUniqChar(s4) << endl; //输出3
	cout << Solution().firstUniqChar(s5) << endl; //输出-1
	return 0;
}