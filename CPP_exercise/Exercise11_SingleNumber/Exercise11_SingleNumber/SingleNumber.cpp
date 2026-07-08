#define _CRT_SECURE_NO_WARNINGS 1
//【只出现一次的数字1.0】
//给出一个非空整数数组nums
//nums中除了某个元素只出现一次以外，其余每个元素均出现两次
//找出只出现了一次的元素并返回
//要求使用线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间

#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int val = 0;
		for (auto n : nums)
			val ^= n;
		return val;
	}
};

int main()
{
	int arr[] = { 1,1,6,2,7,3,2,3,9,9,7 };
	vector<int> n(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto v : n)
		cout << v << " ";
	cout << endl << endl;
	cout << (Solution().singleNumber(n)) << endl;
	return 0;
}