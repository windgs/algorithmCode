// dfs-test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include<iostream>
#include<cstring>
using namespace std;



// 已知 n 个整数b1, b2, …, bn
// 
// 以及一个整数 k（k＜n）。
// 
// 从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。
// 
// 例如当 n = 4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：
// 3＋7＋12 = 22　　3＋7＋19＝29　　7＋12＋19＝38　　3＋12＋19＝34。
// 现在，要求你计算出和为素数共有多少种。
// 
// 例如上例，只有一种的和为素数：3＋7＋19＝29。

bool isprime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}//判断素数 

int a[22];
int b[22];
int p[22];
bool vis[22];
int n, k, sum, ans;

void dfs(int index)
{
	cout << "index=" << index<<" k="<< k+1<<endl;
	if (index == k + 1)
	{
		if (isprime(sum))
			ans++;//看是否加起来是素数 
		for (int i = 1; i <= index - 1; i++)
			cout << p[i] << " ";
		cout << endl;
		return;
	}


	for (int i = 1; i <= n; i++)
	{
		cout << "开始循环 i=" << i << endl;
		if (vis[i] == false && i > p[index - 1])//保证这个排列是按顺序来的，避免重复计算导致答案错误 
		{

			p[index] = i;
			vis[i] = true;
			sum += a[i];//最巧妙的地方，，利用全排列的排列过程中，来加上我输入的数字 

			cout << "+++sum=" << sum-a[i] << "+"<< a[i] <<" index="<< index << " p["<<index<<"]="<< p[index] <<" i=" << i << " a[i]=" << a[i] << endl;
			dfs(index + 1);
			

			vis[i] = false;
			sum -= a[i];//有加就有减 
			cout << "---sum=" << sum + a[i] << "-" << a[i] << " i=" << i << " a[i]=" << a[i] << endl << endl;
		}
	}
}


int main()
{
	memset(b, 0, sizeof(b));
	memset(vis, 0, sizeof(vis));

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], p[i] = i;//一开始要从第一个排列填好  才开始遍历 ，这与传统的dfs全排列做了点变化 
		
	cout << n << p << endl;;

	ans = 0;

	dfs(1);
	cout << ans << endl;

	return 0;
}
//妈的，这个答案真巧妙 
