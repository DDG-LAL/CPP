#define _CRT_SECURE_NO_WARNINGS 1
//【数组中第k个最大元素】
//给定整数数组nums和整数k，要求返回数组中第k个最大的元素
//要求实现时间复杂度为O(N)

#include<iostream>
#include<queue>
#include<vector>
using std::vector;
using std::priority_queue;
using std::cout;
using std::endl;

class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		//priority_queue<int> pq;
		//for (auto e : nums)
		//	pq.push(e);
		//for (int i = 0; i < k - 1; ++i)
		//	pq.pop();
		//return pq.top();
		priority_queue<int> pq(nums.begin(), nums.end());
		while (--k) //执行k-1次
			pq.pop();
		return pq.top();
	}
};

int main()
{
	vector<int> v = { 4,3,2,6,7,1,5,9,0,11 };
	cout << (Solution().findKthLargest(v, 3)) << endl; //7
	return 0;
}