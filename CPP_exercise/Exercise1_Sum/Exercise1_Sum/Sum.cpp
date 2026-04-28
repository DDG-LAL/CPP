#define _CRT_SECURE_NO_WARNINGS 1
//【求和】
//求1+2+...+n
//要求不能使用乘除法、for、while、if、else、switch、case等关键字
//不能使用条件判断语句（A ? B : C）、位运算
//数据范围：
//0 < n ≤ 200

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define n 100 //需要变长数组，但VS不支持

class Solution
{
public:
	class Sum
	{
	public:
		Sum()
		{
			_sumret += _i++;
		}
	};
	int Sum_Solution()
	{
		Sum tmp[n]; //调用n次构造函数
		return _sumret;
	}
private:
	static int _sumret;
	static int _i;
};
int Solution::_sumret = 0; //初始化静态变量
int Solution::_i = 1;

int main()
{
	cout << Solution().Sum_Solution() << endl; //1+2+...+100=5050
	return 0;
}