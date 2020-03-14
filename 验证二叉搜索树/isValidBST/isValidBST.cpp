// isValidBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
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
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
	2
   / \
  1   3
输出: true
示例 2:

输入:
	5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct TreeNode
{
	TreeNode(int x) :val(x),left(NULL),right(NULL) {}
	int val;
	TreeNode* left;
	TreeNode* right;
	
};

class Solution
{
public:
	bool isValid;
	//递归调用判断每个节点和左孩子和右兄弟的值，查看是否不满足条件
	bool isValidBST(TreeNode* root)
	{		
		if (!root)
			return isValid;

		if (root->left)
		{
			if (root->left->val >= root->val)
				isValid = false;
			else
				isValidBST(root->left);
		}

		if (root->right)
		{
			if (root->right->val <= root->val)
				isValid = false;
			else
				isValidBST(root->right);
		}
		return isValid;
		
	}
protected:
private:
};
int main()
{
	Solution so;
	so.isValid = true;
	TreeNode *ptn5 = new TreeNode(5);
	TreeNode *ptn3 = new TreeNode(3);
	TreeNode *ptn7 = new TreeNode(7);
	TreeNode *ptn2 = new TreeNode(2);
	TreeNode *ptn4 = new TreeNode(4);
	TreeNode *ptn6 = new TreeNode(9);
	TreeNode *ptn8 = new TreeNode(8);
	ptn5->left = ptn3;
	ptn5->right = ptn7;
	ptn3->left = ptn2;
	ptn3->right = ptn4;
	ptn7->left = ptn6;
	ptn7->right = ptn8;
	int isValid = so.isValidBST(ptn5);
	cout << "isValid=" << isValid << endl;
	std::cout << "Hello World!\n";
}