// maxSlidingWindow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int> vt;
	vt.clear();
	if (nums.size() == 0)
		return;

	const int n = nums.size();
	int left_max[5]={ 0 };
	left_max[0] = nums[0];
	int right_max[5] = { 0 };
	right_max[-1] = nums[-1];

	vector<int> res;
// 	for i in range(1, n) :
// 		left_max[i] = nums[i] if i % k == 0 else max(left_max[i - 1], nums[i])
// 		print('left_max=', left_max)
// 
// 		for i in range(n - 2, -1, -1) :
// 			right_max[i] = nums[i] if i % k == 0 else max(right_max[i + 1], nums[i])
// 			print('right_max=', right_max)
// 			i = 0
// 			while i + k - 1 < n :
// 				res.append(max(right_max[i], left_max[i + k - 1]))
// 				i += 1
// 				return res
	return res;
}

				
int main()
{
	vector<int> vt;
	maxSlidingWindow(vt, 10);
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
