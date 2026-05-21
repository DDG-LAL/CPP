#define _CRT_SECURE_NO_WARNINGS 1

#include"MyVector.h"
#include<string>
using namespace MyVector;
using std::string;

template<class T>
void print(const vector<T>& v)
{
	for (const auto& e : v)
		cout << e << " ";
	cout << endl << endl;
}


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
	cout << "v1:\n";
	for (size_t i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
		cout << *it++ << " ";
	cout << endl;

	print(v1);
	v1.pop_back();
	print(v1);
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	print(v1);

	vector<int> v2;
	v2.resize(10);
	cout << "   vector<int> v2: "; print(v2);
	vector<int*> v3;
	v3.resize(5);
	cout << "  vector<int*> v3: "; print(v3);
	vector<string> v4;
	v4.resize(5);
	cout << "vector<string> v4: "; print(v4);
	v4.resize(7, string("abc")); //匿名对象
	cout << "vector<string> v4: "; print(v4);
	v4.resize(9, "snt"); //隐式类型转换
	cout << "vector<string> v4: "; print(v4);

	vector<int> v5;
	cout << "v5:\n";
	v5.push_back(0);
	v5.push_back(1);
	v5.push_back(2);
	print(v5);
	vector<int>::iterator pos = v5.begin();
	v5.insert(pos + 1, 6); pos = v5.begin();
	v5.insert(pos + 3, 6); pos = v5.begin();
	print(v5);

	v5.erase(pos + 2); pos = v5.begin();
	print(v5);
	v5.erase(pos); pos = v5.begin();
	print(v5);

	vector<int> v6;
	cout << "v6:\n";
	v6.push_back(1);
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(2);
	v6.push_back(3);
	v6.push_back(6);
	print(v6);
	it = v6.begin();
	while (it != v6.end())
	{
		if (*it % 2 == 0) //检查是否为偶数，是偶数则删除
			it = v6.erase(it); //通过返回值解决迭代器失效
		else
			++it;
	}
	print(v6);

	vector<int> v7(v6); //拷贝构造
	cout << "v7:\n";
	print(v7);
	v7 = v2; //赋值重载
	print(v7);

	vector<int> v8(v7.begin(), v7.begin() + 5); //迭代器区间构造
	cout << "v8:\n";
	print(v8);

	vector<int> v9(10, 1); //用给定数量的相同对象进行构造
	cout << "v9:\n";
	print(v9);
	vector<string> v10(10, "sn"); //用给定数量的相同对象进行构造
	cout << "v10:\n";
	print(v10);

	return 0;
}