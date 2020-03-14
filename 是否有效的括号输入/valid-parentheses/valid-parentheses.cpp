// valid-parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <string>
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
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

注意入栈和出栈的顺序：([)]
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') stack.push(')');
			else if (s[i] == '{') stack.push('}');
			else if (s[i] == '[') stack.push(']');
			else if (stack.empty() || stack.top() != s[i]) return false;
			else stack.pop();
		}
		return stack.empty();
	}
};

int main()
{
	Solution s;
	string str("[]");
	cout << str.length() << endl;
	cout << str.size() << endl;
	s.isValid(str);
	return 0;
}