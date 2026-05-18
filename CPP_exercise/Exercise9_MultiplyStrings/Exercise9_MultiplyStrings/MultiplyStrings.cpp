#define _CRT_SECURE_NO_WARNINGS 1
//【字符串相乘】
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//不允许使用任何内置的BigInteger库
//不允许直接将输入转换为整数

#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::cout;
using std::endl;
using std::reverse;
using std::vector;

class Solution
{
public:
	string multiplyStrings1(string& num1, string& num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		string ret = "0";
		string tmp;
		int i1 = num1.size() - 1; //下标
		while (i1 >= 0)
		{
			int next = 0; //进位
			int n1 = i1 >= 0 ? num1[i1] - '0' : 0; //取num1的当前位
			int tenfold = num1.size() - 1 - i1; //十倍数
			int i2 = num2.size() - 1; //下标
			while (i2 >= 0)
			{
				int n2 = i2 >= 0 ? num2[i2] - '0' : 0; //取num2的当前位
				int mul = n1 * n2 + next; //求乘积
				next = mul / 10; //确定进位
				tmp += ('0' + (mul % 10)); //确定个位，并尾插到tmp字符串
				--i2;
			}
			if (next != 0) //最高位进位的情况
				tmp += ('0' + next);
			reverse(tmp.begin(), tmp.end()); //反转
			while (tenfold-- > 0) //根据高位相乘的十倍数，在tmp末尾补0
				tmp += '0';
			ret = addStrings(ret, tmp); //将所得的值加在ret字符串里
			tmp.clear(); //清空tmp字符串
			--i1;
		}
		return ret;
	}
	string addStrings(string& num1, string& num2)
	{
		string ret;
		int i1 = num1.size() - 1; //下标
		int i2 = num2.size() - 1;
		int next = 0;
		while (i1 >= 0 || i2 >= 0)
		{
			int n1 = i1 >= 0 ? num1[i1] - '0' : 0; //取num1的当前位
			int n2 = i2 >= 0 ? num2[i2] - '0' : 0; //取num2的当前位
			int sum = n1 + n2 + next; //求和
			next = sum / 10; //确定进位
			sum %= 10; //确定个位
			ret += ('0' + sum); //尾插到ret字符串
			--i1;
			--i2;
		}
		if (next != 0) //最高位进位的情况
			ret += ('0' + next);
		reverse(ret.begin(), ret.end()); //反转字符串
		return ret;
	}
	string multiplyStrings2(string& num1, string& num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";

		int i1 = num1.size(), i2 = num2.size(); //下标
		vector<int> ret_arr(i1 + i2, 0);
		//长度为i1和长度为i2的两个数相乘，积的长度只可能是i1+i2或i1+i2-1
		//对num1和num2同时取最大值可得长度为i1+i2，对num1和num2同时取最小值可得长度为i1+i2-1

		for (int i = i1 - 1; i >= 0; --i)
		{
			int n1 = num1[i] - '0'; //取num1的当前位
			for (int j = i2 - 1; j >= 0; --j)
			{
				int n2 = num2[j] - '0'; //取num2的当前位
				ret_arr[i + j + 1] += n1 * n2; //num1的下标i位和num2的下标j位相乘，放入ret_arr[i + j + 1]
			}
		}
		//num1的下标i位和num2的下标j位相乘，设num1的长度为size1，num2的长度为size2
		//可以视为n1*10^(size1-i-1)与n2*10^(size2-j-1)相乘，两数的长度分别为size1-i和size2-j	
		//因此积的长度为size1+size2-i-j或size1+size2-i-j-1，取较小值，因为较大值的情况会被进位处理		   
		//而ret_arr的长度为size1+size2														   a:     012   la=3    
		//若长度为la的短数组a要逐位对应且右侧对齐地放入长度为lb的长数组b，则a[0]对应的是b[lb-la]	   b: 0123456   lb=7
		//因此n1*n2应放入的下标为size1+size2-(size1+size2-i-j-1)，即i+j						   a[0]对应b[4]，即b[7-3]

		for (int i = i1 + i2 - 1; i > 0; --i) //处理进位
		{
			ret_arr[i - 1] += ret_arr[i] / 10; //将个位以上的数加到上一位
			ret_arr[i] %= 10; //当前位只留下个位
		}

		int index = ret_arr[0] == 0 ? 1 : 0;
		//若长度为i1+i2，则数组有效下标从0开始，若长度为i1+i2-1，则数组有效下标从1开始
		//长度为i1和长度为i2的两个数相乘，积的长度只可能是i1+i2或i1+i2-1

		string ret;
		while (index < i1 + i2)
			ret += ret_arr[index++]; //将ret_arr数组中的结果尾插到ret字符串
		for (auto& c : ret)
			c += '0'; //将每一个字符从整型值转化为字符对应的ASCII值
		return ret;
	}
};

int main()
{
	string n1 = "9127593";
	string n2 = "7563255";
	cout << n1 << " × " << n2 << " =" << endl;
	cout << (Solution().multiplyStrings1(n1, n2)) << endl << endl; //69034313395215
	cout << n1 << " × " << n2 << " =" << endl;
	cout << (Solution().multiplyStrings2(n1, n2)) << endl << endl; //69034313395215
	return 0;
}