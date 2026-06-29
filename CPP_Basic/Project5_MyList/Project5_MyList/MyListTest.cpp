#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<string>
#include"MyList.h"
using namespace MyList;
using std::string;
using std::vector;

struct testA
{
	testA(int a1 = 0, int a2 = 0)
		: _a1(a1)
		, _a2(a2)
	{}

	int _a1;
	int _a2;
};

int main()
{
	list<int> lt0;
	lt0.push_back(0);
	lt0.push_back(1);
	lt0.push_back(2);
	lt0.push_back(3);
	lt0.push_back(4);
	lt0.push_back(5);
	lt0.push_front(11);
	lt0.push_front(33);
	lt0.push_front(55);

	list<int>::iterator it = lt0.begin();
	while (it != lt0.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl << endl;
	for (auto e : lt0)
		cout << e << " ";
	cout << endl << endl;

	list<int> lt1 = lt0;
	lt1.pop_back();
	lt1.pop_back();
	lt1.pop_front();
	for (auto e : lt1)
		cout << e << " ";
	cout << endl << endl;

	lt0 = lt1;
	for (auto e : lt0)
		cout << e << " ";
	cout << endl << endl;

	list<testA> lt3;
	lt3.push_back(testA(0, 1));
	lt3.push_back(testA(0, 2));
	lt3.push_back(testA(0, 3));
	auto it3 = lt3.begin();
	while (it3 != lt3.end())
	{
		cout << (*it3)._a1 << " " << (*it3)._a2 << endl;
		cout << it3->_a1 << " " << it3->_a2 << endl;
		cout << it3.operator->()->_a1 << " " << it3.operator->()->_a2 << endl;
		++it3;
	} //it3->a1实际上是it3->->a1，编译器为了可读性省略了一个->
	cout << endl << endl;

	list<string> lt4;
	lt4.push_back("qwert");
	lt4.push_back("asdfg");
	lt4.push_back("zxcv");
	//print_list(lt4);
	print_container(lt4);
	cout << endl;

	vector<string> v;
	v.push_back("qwert");
	v.push_back("asdfg");
	v.push_back("zxcv");
	print_container(v);
	cout << endl;

	return 0;
}