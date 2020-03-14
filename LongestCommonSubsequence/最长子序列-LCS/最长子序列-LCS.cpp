// 最长子序列-LCS.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
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
动态规划
假设Z=<z1,z2,⋯,zk>是X与Y的LCS， 我们观察到
如果Xm=Yn，则Zk=Xm=Yn，有Zk等于 Xm−1与Yn−1的LCS+1；
如果Xm≠Yn，则Zk等于 Xm与Yn−1的LCS，或者是Xm−1与Yn的LCS。
因此，求解LCS的问题则变成递归求解的两个子问题。但是，上述的递归求解的办法中，重复的子问题多，效率低下。改进的办法——用空间换时间，用数组保存中间状态，方便后面的计算。这就是动态规划（DP)的核心思想了
*/
//#########################--1--################################
int lcs(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size(); 
	char ch[100] = {};
	int idx = 0;
	int c[100][100] = { 0 };
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			c[i][j] = 0;
		}
	}
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1.at(i-1) == str2.at(j-1)) {
				//cout << str1.at(i - 1) << endl;
				ch[idx++] = str1.at(i - 1);
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
			}
		}
	}
	cout << "lcs_substr=" << ch << endl;
	return c[len1][len2];
}

//#########################--2--################################
int lcs2(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	char ch[100] = {};
	int idx = 0;
	int result = 0;     //记录最长公共子串长度
	int c[100][100] = { 0 };
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			c[i][j] = 0;
		}
	}
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			//0号位
			if (i == 0 || j == 0) {
				result = 0;
			}
			//1号位开始
			else if (str1.at(i - 1) == str2.at(j - 1)) {
				//cout << str1.at(i - 1) << endl;
				ch[idx++] = str1.at(i - 1);			//记录相同字符
				
				//如果Xm=Yn，则Zk=Xm=Yn，有Zk等于 Xm−1与Yn−1的LCS+1；
				c[i][j] = c[i - 1][j - 1] + 1;

				result = max(c[i][j], result);
			}
			else {
				result = 0;
			}
		}
	}
	cout << "lcs_substr=" << ch << endl;
	return result;
}

//#########################--3--################################
//最长公共子串:和LCS问题唯一不同的地方在于当A[i] != B[j]时，res[i][j]就直接等于0了，因为子串必须连续，且res[i][j] 表示的是以A[i]，B[j]截尾的公共子串的长度
int lcs3(string& str1, string& str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int ch[100][100] = {};
	int result = 0;
	int idx = 0;
	int c[100][100] = { 0 };

	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			c[i][j] = 0;
		}
	}
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
			else if (str1.at(i - 1) == str2.at(j - 1)) {
				cout << str1.at(i - 1) << endl;
				ch[i][j] = str1.at(i - 1);

				//A[i]，B[j]截尾的公共子串的长度
				c[i][j] = c[i - 1][j - 1] + 1;
				result = max(c[i][j], result);
			}
		}
	}
	cout << "lcs_substr=" << ch << endl;
	return result;
}

//###############################--4--##########################
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
const int MAXL(1e3);
int flag[MAXL + 50][MAXL + 50];
char s1[MAXL + 50], s2[MAXL + 50];
int dp[MAXL + 50][MAXL + 50];

void LCS()
{
	memset(dp, 0, sizeof(dp));
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= strlen(s1); i++)
	{
		for (int j = 1; j <= strlen(s2); j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				flag[i][j] = 0;
			}
			else if (dp[i - 1][j] >= dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
				flag[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
				flag[i][j] = -1;
			}
		}
	}
}
void PrintLCS(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (flag[i][j] == 0)
	{
		PrintLCS(i - 1, j - 1);
		cout << s1[i - 1];
	}
	else if (flag[i][j] == 1)
		PrintLCS(i - 1, j);
	else
		PrintLCS(i, j - 1);
}
//#########################################################

int main()
{
	string str1("seaoyfg");
	string str2("euaoftg");

	str1 = "helloworld";
	str2 = "loop"; 
	cout << "str1=" << str1 << endl;
	cout << "str2=" << str2 << endl;

// 	int lcs_len = lcs(str1, str2);
// 	cout << "lcs_len=" << lcs_len << endl;
// 
// 	cout << "最长公共子序列" << endl;
// 	lcs_len = lcs2(str1, str2);
// 	cout << "lcs_len=" << lcs_len << endl;

	cout << "最长公共子串" << endl;
	int lcs_len = lcs3(str1, str2);
	cout << "lcs_len=" << lcs_len << endl;

	while (cin >> s1 >> s2)
	{
		LCS();
		PrintLCS(strlen(s1), strlen(s2));
		cout << endl;
	}

	return 0;
}