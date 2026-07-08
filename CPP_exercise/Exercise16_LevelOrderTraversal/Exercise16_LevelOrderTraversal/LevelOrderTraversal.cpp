#define _CRT_SECURE_NO_WARNINGS 1
//【二叉树的分层层序遍历】
//给出二叉树的根节点root，返回其节点值的层序遍历
//要求逐层访问，分层展示

#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using std::endl;
using std::cout;
using std::stack;
using std::vector;
using std::queue;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* BuyNode(int x) //创建节点
{
	TreeNode* newnode = new TreeNode;
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void BTdestroy(TreeNode* root) //销毁二叉树
{
	if (!root)
		return;
	BTdestroy(root->left);
	BTdestroy(root->right);
	delete root;
}

struct TreeNode* CreateBinaryTree() //创建二叉树
{
	TreeNode* node1 = BuyNode(1);
	TreeNode* node2 = BuyNode(2);
	TreeNode* node3 = BuyNode(3);
	TreeNode* node4 = BuyNode(4);
	TreeNode* node5 = BuyNode(5);
	TreeNode* node6 = BuyNode(6);
	TreeNode* node7 = BuyNode(7);
	TreeNode* node8 = BuyNode(8);
	TreeNode* node9 = BuyNode(9);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->left = node7;
	node5->right = node8;
	node7->left = node9;
	return node1;
}

class Solution1 //双queue
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;
		queue<TreeNode*> qdata;
		queue<int> level;
		int levelcount = 0; //记录节点的层数
		if (root)
		{
			qdata.push(root);
			level.push(levelcount);
		}
		while (!qdata.empty())
		{
			TreeNode* front = qdata.front();
			levelcount = level.front();
			qdata.pop();
			level.pop();

			if (levelcount == ret.size()) //确保vector的行数等于层数
				ret.push_back(vector<int>());

			ret[levelcount].push_back(front->val); //数据进入levelcount对应的行
			if (front->left)
			{
				qdata.push(front->left);
				level.push(levelcount + 1);
			}
			if (front->right)
			{
				qdata.push(front->right);
				level.push(levelcount + 1);
			}
		}
		return ret;
	}
};

class Solution2 //双vector
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ret;
		vector<TreeNode*> cur; //当前行
		vector<TreeNode*> next; //下一行
		int levelcount = 0; //记录层数
		if (root)
			cur.push_back(root);
		while (!cur.empty())
		{
			ret.push_back(vector<int>()); //新建一行
			for (auto e : cur)
			{
				ret[levelcount].push_back(e->val); //数据进入当前行的vector
				if (e->left)
					next.push_back(e->left);
				if (e->right)
					next.push_back(e->right);
			}
			cur.clear(); //清空当前行
			cur.swap(next); //把下一行的数据换到当前行
			++levelcount; //当前行数加一
		}
		return ret;
	}
};

class Solution3 //单queue配合levelSize变量
{
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		queue<TreeNode*> qdata;
		vector<vector<int>> ret;
		size_t levelSize = 0;
		if (root)
		{
			qdata.push(root);
			levelSize = 1; //当前层的节点数
		}
		while (!qdata.empty())
		{
			vector<int> row; //存放一行数据的vector

			while (levelSize--) //处理一层的节点，levelSize为当前层的节点数
			{
				TreeNode* front = qdata.front(); //取当前层的单个节点
				qdata.pop(); //当前节点出队列，使得下一次的front取到下一个节点
				row.push_back(front->val); //当前层的数据进入同一行的vector

				if (front->left) //若下一层有数据，则将下一层的节点入队列
					qdata.push(front->left);
				if (front->right) //若下一层有数据，则将下一层的节点入队列
					qdata.push(front->right);
			}
			ret.push_back(row); //一行完成，进入ret
			levelSize = qdata.size(); //当前队列的元素个数即为下一层的节点个数
		}
		return ret;
	}
};

void print(vector<vector<int>> v)
{
	for (auto l : v)
	{
		for (auto e : l)
			cout << e << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> v;

	auto root1 = CreateBinaryTree();
	v = Solution1().levelOrder(root1);
	print(v);

	auto root2 = CreateBinaryTree();
	v = Solution2().levelOrder(root2);
	print(v);

	auto root3 = CreateBinaryTree();
	v = Solution3().levelOrder(root3);
	print(v);

	return 0;
}