// buildTree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

	3
   / \
  9  20
	/  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct TreeNode
{
	TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL){}
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next;

};

class Solution
{
public:
	//递归构造二叉树
	TreeNode* buildTree(vector<int>&preorder, vector<int>& inorder)
	{
		if (preorder.empty())
			return NULL;

		TreeNode* pRoot = new TreeNode(preorder[0]);

		//找出root节点，在先序0号位
		int rootVal = preorder[0];

		//前序遍历左右序列
		vector<int> preLeftV;
		vector<int> preRightV;
		//中序遍历左右序列
		vector<int> minLeftV;
		vector<int> minRightV;
		bool reachRoot = false;
		int nMin = 0;

		//在中序遍历数组中找到root节点的位置，划分出左右孩子节点数组
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == rootVal)
			{
				//此处为root节点的位置，即可得出中序遍历中有多少个左孩子节点
				nMin = i;
				reachRoot = !reachRoot;
				continue;
			}
			if (reachRoot)
			{
				cout << "inorder-right-val= " << inorder[i] << endl;
				minRightV.push_back(inorder[i]);
			}
			else
			{
				cout << "inorder-left-val= " << inorder[i] << endl;
				minLeftV.push_back(inorder[i]);
			}
		}

		//求出前序遍历中的左右孩子节点数组
		for (int i = 1; i < preorder.size(); i++)
		{
			if (i > nMin)
			{
				cout << "preorder-right-val= " << preorder[i] << endl;
				preRightV.push_back(preorder[i]);
			}
			else
			{
				cout << "preorder-left-val= " << preorder[i] << endl;
				preLeftV.push_back(preorder[i]);
			}
		}

		//递归构造二叉树
		//构建左子树
		pRoot->left = buildTree(preLeftV, minLeftV);
		//构建右子树
		pRoot->right = buildTree(preRightV, minRightV);

		return pRoot;
	}

	void fallten(TreeNode* root)
	{
		if (!root)
			return;
		if(root->left)
			root->next = root->left;
		if (root->next)
		{
			fallten(root->next);
			root->next->next = root->right;
		}
		if(root->right)
			fallten(root->next->next);

	}

	void buildChildTree(vector<int>&vt, TreeNode*& rpNode)
	{
		//构建左子树
		bool createRoot = true;
		TreeNode* ptL = NULL;
		TreeNode* ptRoot = NULL;
		TreeNode* ptRight = NULL;
		for (int i = 0; i < vt.size(); i++)
		{
			if (i == 0)
			{
				ptL = new TreeNode(vt[i]);
				continue;
			}

			if (createRoot)
			{
				ptRoot = new TreeNode(vt[i]);
				ptRoot->left = ptL;
			}
			else
			{
				ptRight = new TreeNode(vt[i]);
				ptRoot->right = ptRight;
			}
			createRoot = !createRoot;
			ptL = ptRoot;
		}

		//左半边部分和root节点进行连接
		rpNode = ptL;
	}
protected:
private:
};

int main()
{
	Solution so;
	vector<int> preorder;
	vector<int> inorder;
	int narr1[] = { 3,9,8,5,10,20,15,7 };
	int narr2[] = { 5,8,9,10,3,15,20,7 };
	for (int i=0; i<sizeof(narr1)/sizeof(int); i++)
	{
		preorder.push_back(narr1[i]);
	}
	for (int i = 0; i < sizeof(narr1) / sizeof(int); i++)
	{
		inorder.push_back(narr2[i]);
	}
	TreeNode* pNode = so.buildTree(preorder, inorder);
	so.fallten(pNode);
	std::cout << "Hello World!\n";
}