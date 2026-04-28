#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

int main()
{
	Date d1(2001, 6, 3);
	Date d2(d1);
	Date d3;
	cout << "d1:";
	d1.print();
	cout << "d2:";
	d2.print();
	cout << "d3:";
	d3.print();

	d3 = d1;
	cout << "\nd3 = d1\nd3:";
	d3.print();
	d3 += 100;
	cout << "\nd3 += 100\nd3:";
	d3.print();
	d1 -= 100;
	cout << "\nd1 -= 100\nd1:";
	d1.print();

	cout << endl << (d3 > d1 ? "d3>d1" : "d3<=d1") << endl;

	Date ret1 = d2--;
	cout << "\nret1 = d2--\nret1:";
	ret1.print();
	cout << "d2:";
	d2.print();
	Date ret2 = --d2;
	cout << "\nret2 = --d2\nret2:";
	ret2.print();
	cout << "d2:";
	d2.print();

	Date d4(1874, 3, 6);
	cout << "\nd4:";
	d4.print();
	Date d5(2011, 12, 6);
	cout << "d5:";
	d5.print();

	cout << "d5 - d4 = " << (d5 - d4) << endl;
	cout << "d4 - d5 = " << (d4 - d5) << endl;

	cout << "\nd5:" << d5 << endl;

	cout << "modify d5:";
	cin >> d5;
	cout << "\nd5:" << d5 << endl;

	return 0;
}