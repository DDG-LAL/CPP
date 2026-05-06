#define _CRT_SECURE_NO_WARNINGS 1

#include"MyString.h"
using namespace MyString;

int main()
{
	string s1("123_456_abc");
	cout << s1.c_str() << endl;
	string s2;
	cout << s2.c_str() << endl;

	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl << endl;

	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		++(*it);
		cout << *it++ << " ";
	}
	cout << endl << s1.c_str() << endl << endl;

	for (auto ch : s1) //范围for的实现是基于格式固定的迭代器的替换
	{				   //相当于把*it赋值给ch，因此直接修改ch无法修改s1
		++ch;
		cout << ch << " ";
	}
	cout << endl << s1.c_str() << endl << endl;

	for (auto& ch : s1) //使用引用，可以修改s1
	{
		++ch;
		cout << ch << " ";
	}
	cout << endl << s1.c_str() << endl << endl;


	s2.append("qwert");
	cout << s2.c_str() << endl;
	s2.push_back('+');
	cout << s2.c_str() << endl;
	s2 += '!';
	cout << s2.c_str() << endl;
	s2 += "jkl";
	cout << s2.c_str() << endl;

	s2.erase(0);
	cout << s2.c_str() << 'a' << endl;
	s2 += "123456789";
	cout << s2.c_str() << endl;
	s2.erase(3, 2);
	cout << s2.c_str() << endl;
	s2.erase(0, 3);
	cout << s2.c_str() << endl;
	s2.erase(0);
	s2 += "123456789";
	s2.insert(3, 'a');
	cout << s2.c_str() << endl;
	s2.insert(4, "ABC");
	cout << s2.c_str() << endl;
	s2.insert(0, "-");
	cout << s2.c_str() << endl;

	string s3;
	cout << "\ns3:";
	cin >> s3;
	cout << s3 << endl;

	return 0;
}