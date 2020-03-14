// wordBreak.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
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

//动态规划
class Solution {
public:
	bool isExit(string s1, vector<string>& wordDict) {
		if (s1.empty())
		{
			return false;
		}
		for (auto iter: wordDict)
		{
			if (iter == s1)
				return true;
		}
		return false;
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i=1; i<=s.size(); i++)
		{
			for (int j=i-1; j>=0; j--)
			{
				//从后往前取字符串第j位置，取i-j个
				string substr = s.substr(j, i-j);
				cout << "i=" << i << " j=" << j << " substr=" << substr << endl;
				if (isExit(substr, wordDict) && !dp[i])
				{
					cout << "**************** find substr = " << substr << " ********************"<< endl;
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
};


int main()
{
	Solution s;
	string str("applepenapple");
	vector<string> wordDict;
	wordDict.push_back("apple");
	wordDict.push_back("pen");
	s.wordBreak(str, wordDict);
	std::cout << "Hello World!\n";
}
