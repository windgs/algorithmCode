// faltten.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

	1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
	3
	 \
	  4
	   \
		5
		 \
		  6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct TreeNode
{
	TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* next;

};

class Solution
{
public:
	void fallten(TreeNode* root)
	{
		
		TreeNode* pLeft = root->left;
		root->next = root->left;
		fallten(root->next);
		root->next->next = root->right;
		fallten(root->next->next);
		
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
	for (int i = 0; i < sizeof(narr1) / sizeof(int); i++)
	{
		preorder.push_back(narr1[i]);
	}
	for (int i = 0; i < sizeof(narr1) / sizeof(int); i++)
	{
		inorder.push_back(narr2[i]);
	}
	std::cout << "Hello World!\n";
}