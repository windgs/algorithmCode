// isAnagram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <unordered_map>
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
字母异位词 ： 组合在一起。字母异位词指字母相同，但排列不同的字符串
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 思路一：排序
// 排序后判断是否相等。
// 代码

class Solution {
public:
	bool isAnagram(string& s, string& t) {
		if (s.size() != t.size()) {
			return false;
		}
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}


// 思路二：哈希表（最优解）
// 代码
	bool isAnagram2(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<int, int> umap;
		for (char ch : s) {
			++umap[ch];
		}
		for (char ch : t) {
			if (umap[ch] > 0) {
				--umap[ch];
			}
			else {
				return false;
			}
		}
		return true;
	}

//另一种写法
	bool isAnagram3(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> umap;
		for (int i = 0; i < s.size(); ++i) {
			++umap[s[i]];
			--umap[t[i]];
		}
		for (auto c : umap) {
			if (c.second != 0) {
				return false;
			}
		}
		return true;
	}
};



int main()
{
	Solution s;
	string str1("anagram");
	string str2("nagaram");
	s.isAnagram3(str1, str2);
	return 0;
}