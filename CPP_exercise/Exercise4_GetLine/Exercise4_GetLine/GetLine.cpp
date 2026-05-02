#define _CRT_SECURE_NO_WARNINGS 1
//【求字符串最后一个单词的长度】
//在一行上输入若干个字符串，每个字符串代表一个单词
//每个单词均由大小写字母混合构成，单词间使用单个空格分隔
//输出最后一个单词的长度

#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
	string s;
	rewind(stdin); //清空标准输入缓冲区的内容
	getline(cin, s); //获取一行的字符内容写入s，以换行符作为结尾标识
	size_t i = s.rfind(' ');
	if (i == string::npos)
		cout << s.size();
	else
		cout << s.size() - (i + 1);

	//cin >> s; //获取一个字符串的内容写入s，以' '或换行符作为结尾标识

	getline(cin, s); //获取一行的字符内容写入s，以换行符作为结尾标识
	cout << endl << s << endl << endl;

	getline(cin, s, '*'); //获取一个字符串的内容写入s，以'*'作为结尾标识
						  //此时换行符和' '都不会被识别为结尾
	cout << endl << s << endl;

	return 0;
}


