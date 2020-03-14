// robot.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：

U: 向y轴正方向移动一格
R: 向x轴正方向移动一格。
不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。

 

示例 1：

输入：command = "URR", obstacles = [], x = 3, y = 2
输出：true
解释：U(0, 1) -> R(1, 1) -> R(2, 1) -> U(2, 2) -> R(3, 2)。
示例 2：

输入：command = "URR", obstacles = [[2, 2]], x = 3, y = 2
输出：false
解释：机器人在到达终点前会碰到(2, 2)的障碍物。
示例 3：

输入：command = "URR", obstacles = [[4, 2]], x = 3, y = 2
输出：true
解释：到达终点后，再碰到障碍物也不影响返回结果。
 

限制：

2 <= command的长度 <= 1000
command由U，R构成，且至少有一个U，至少有一个R
0 <= x <= 1e9, 0 <= y <= 1e9
0 <= obstacles的长度 <= 1000
obstacles[i]不为原点或者终点

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/programmable-robot
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//动态规划
class Solution {
public:
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		map<int, bool> map_;
		int x_per_pos = 0;
		int y_per_pos = 0;
		for (auto chr : command)
		{
			if (chr == 'U')
				y_per_pos++;
			else if (chr == 'R')
				x_per_pos++;

			int mKey = (x_per_pos << 9) + y_per_pos;
			cout << "mKey=" << mKey << endl;
			map_[mKey] = true;
		}

		//判断是否可以达到(x,y)
		int circle = min(x / x_per_pos, y / y_per_pos);
		int fKey = ((x - circle * x_per_pos) << 9) + (y - circle * y_per_pos);
		if (map_[fKey] == false)
		{
			return false;
		}

		//判断障碍点是否在
		for (auto obsPos : obstacles)
		{
			circle = min(obsPos[0] / x_per_pos, obsPos[1] / y_per_pos);
			int obsKey = ((obsPos[0] - circle * x_per_pos) << 9) + (obsPos[1] - circle * y_per_pos);
			if (map_[obsKey])
			{
				return false;
			}
		}

		return true;
	}
};

int main()
{
	Solution so;
	string cmd("URRU");
	cout << "cmd=" << cmd << endl;
	vector<vector<int>> obstacles;
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(1);
	cout << "obstacles=" << v1[0] << ", " << v1[1] << endl;
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(4);
	cout << "obstacles=" << v2[0] << ", "<< v2[1] << endl;
	obstacles.push_back(v1);
	obstacles.push_back(v2);
	int x = 12;
	int y = 11;
	cout << "x=" << x << " y="<< y << endl;
	bool isReach = so.robot(cmd, obstacles, x, y);
	cout << "isReach=" << isReach << endl;

	std::cout << "Hello World!\n";
}