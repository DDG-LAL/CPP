#define _CRT_SECURE_NO_WARNINGS 1

#include"MyQueue.h"
using namespace MyQueue;
using std::cout;
using std::endl;

int main()
{
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(9);

	while (!q.empty())
	{
		cout << "front:" << q.front() << " ";
		cout << "back:" << q.back() << " ";
		cout << "size:" << q.size() << endl;
		q.pop();
	}

	return 0;
}