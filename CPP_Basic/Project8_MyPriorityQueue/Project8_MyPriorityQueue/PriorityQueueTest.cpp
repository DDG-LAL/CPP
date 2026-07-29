#define _CRT_SECURE_NO_WARNINGS 1

#include"MyPriorityQueue.h"
using namespace MyPriorityQueue;


int main()
{
	priority_queue<int> q1; //´ó¶Ñ
	q1.push(7);
	q1.push(2);
	q1.push(5);
	q1.push(9);

	while (!q1.empty())
	{
		cout << q1.top() << " "; //9 7 5 2 
		q1.pop();
	}
	cout << endl << endl;

	priority_queue<int, vector<int>, Greater<int>> q2; //Ð¡¶Ñ
	q2.push(7);
	q2.push(2);
	q2.push(5);
	q2.push(9);

	while (!q2.empty())
	{
		cout << q2.top() << " "; //2 5 7 9 
		q2.pop();
	}
	cout << endl;

	return 0;
}