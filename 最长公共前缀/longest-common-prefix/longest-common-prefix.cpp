// longest-common-prefix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
最长公共前缀

武器：修改为二分查找，思路没有记住。首先寻找长度最短的字符串，然后开始折半查找，判断截止到当前mid的字串是不是公共前缀（循环判断每个字符串startWith），如果是low=mid+1，反之high=mid-1；注意返回结果是 return  minShortString.substring(0,(low+high)/2);

结果：未通过
————————————————
版权声明：本文为CSDN博主「hanruikai」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/hanruikai/article/details/86509893
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& S) {
		if (S.empty()) return "";
		//排序后： flight flow flower
		sort(S.begin(), S.end());
		int i = 0;
		string ans = "";
		//取出最小的那个字符串，只要和尾部相等，即和中间的字符串也相等。
		while (i < min(S[0].length(), S.back().length())) {
			if (S[0][i] != S.back()[i])
				break;
			ans += S[0][i];
			i++;
		}
		return ans;
	}

	string longestCommonPrefix2(vector<string>& S) {
		if (S.empty()) return "";
		//取出第一个字符串
		string s0 = S[0];		
		string resStr = "";
		//循环遍历所有字符串数组
		for (int i=1; i<S.size(); i++)
		{
			string tempStr = "";
			//获取最短的字符串进行截取
			int minlen = min(s0.size(), S[i].size());
			s0 = s0.substr(0, minlen);
			if (s0 == "") return "";
			for (int j=0;j<minlen; j++)
			{
				//按位比较
				if (s0[j] != S[i][j])
				{
					break;
				}
				tempStr += s0[j];
				
			}
			resStr = s0 = tempStr;
			cout << "tempStr =" << tempStr << endl;
		}
		cout << "resStr =" << resStr << endl;
		return resStr;
	}
};
int main()
{
	vector<string> S;
	Solution s;
	S.push_back("flower");
	S.push_back("flow");
	S.push_back("flight");
	s.longestCommonPrefix2(S);
	return 0;
}