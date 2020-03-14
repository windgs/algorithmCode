// GroupAnagrams.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
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
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& S) {
		map<string, vector<string>> mv; 
		for (auto str: S)
		{
			vector<string> v;
			string temp = str;
			sort(str.begin(), str.end());
			if (mv.find(str) == mv.end())
				mv[str] = v;			
			mv[str].push_back(temp);		
		}
		
		vector<vector<string>> vv;
		for(auto v: mv)
		{
			cout << "--- vv=" << v.first << " ---" << endl;
			for (auto v1: v.second)
			{
				cout << "v1=" << v1 << endl;
			}
			vv.push_back(v.second);
		}
		
		return vv;
	}
};
int main()
{
	Solution s;
	vector<string> S;
	S.push_back("eat");
	S.push_back("tea");
	S.push_back("tan");
	S.push_back("ate");
	S.push_back("nat");
	S.push_back("bat");
	s.groupAnagrams(S);

	string ss("abc");
	cout << ss.substr(1, 0) << endl;
	return 0;
}