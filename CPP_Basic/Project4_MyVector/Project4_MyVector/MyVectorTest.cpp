#define _CRT_SECURE_NO_WARNINGS 1

#include"MyVector.h"
using namespace MyVector;

int main()
{
	vector<int> v1;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	for (size_t i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
		cout << *it++ << " ";
	cout << endl << endl;

	for (auto e : v1)
		cout << e << " ";
	cout << endl << endl;

	return 0;
}