#define _CRT_SECURE_NO_WARNINGS 1
//【杨辉三角】
//给定一个非负整数numRows，生成杨辉三角的前numRows行
//杨辉三角中，每个数是它左上方和右上方的数的和

#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			vv[i].resize(i + 1, 0);
			vv[i][0] = vv[i][vv[i].size() - 1] = 1;
		}
		for (size_t i = 0; i < vv.size(); ++i)
			for (size_t j = 0; j < vv[i].size(); ++j)
				if (vv[i][j] == 0)
					vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		return vv;
	}
};

void print(const vector<vector<int>>& vv)
{
	for (size_t i = 0; i < vv.size(); ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
			cout << vv[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	auto vv = Solution().generate(20);
	print(vv);
	return 0;
}