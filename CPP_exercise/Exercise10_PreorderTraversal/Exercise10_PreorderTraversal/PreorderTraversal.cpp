#define _CRT_SECURE_NO_WARNINGS 1
//【前序遍历二叉树并返回】
//给出二叉树根节点，以数组形式返回前序遍历

#include<iostream>
#include<vector>
using std::vector;
using std::endl;
using std::cout;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* BuyNode(int x) //创建节点
{
	struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (!newnode)
	{
		perror("malloc\n");
		return NULL;
	}
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void BTdestroy(struct TreeNode* root) //销毁二叉树
{
	if (!root)
		return;
	BTdestroy(root->left);
	BTdestroy(root->right);
	free(root);
}

struct TreeNode* CreateBinaryTree()
{
	struct TreeNode* node1 = BuyNode(1);
	struct TreeNode* node2 = BuyNode(2);
	struct TreeNode* node3 = BuyNode(3);
	struct TreeNode* node4 = BuyNode(4);
	struct TreeNode* node5 = BuyNode(5);
	struct TreeNode* node6 = BuyNode(6);
	struct TreeNode* node7 = BuyNode(7);
	struct TreeNode* node8 = BuyNode(8);
	struct TreeNode* node9 = BuyNode(9);

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

class Solution 
{
public:
	void _preorder(TreeNode* root, vector<int>& v)
	{
		if (root == nullptr)
			return;
		v.push_back(root->val);
		_preorder(root->left, v);
		_preorder(root->right, v);
	}
	vector<int> preorderTraversal(TreeNode* root) 
	{
		vector<int> ret;
		_preorder(root, ret);
		return ret;
	}
};

int main()
{
	struct TreeNode* root = CreateBinaryTree();
	vector<int> vec = Solution().preorderTraversal(root);
	vector<int>::iterator it = vec.begin();
	for (auto v : vec)
		cout << v << " ";
	cout << endl;
	BTdestroy(root);
	root = nullptr;
	return 0;
}