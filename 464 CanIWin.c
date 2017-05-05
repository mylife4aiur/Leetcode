#include "stdafx.h"
#include <iostream>  
#include<unordered_map>
using namespace std;

int main()
{
}

class Solution {
public:
	bool canIWinEASY(int maxChoosableInteger, int desiredTotal) {
		if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
			return false;
		if (desiredTotal <= 0)
			return true;
		unordered_map<int, bool> status;
		int current = 0;
		return DFS_winEASY(current, maxChoosableInteger, desiredTotal);
	}
	bool DFS_winEASY(int current, int &max_choose, int total)
	{
		if (total <= 0)
			return false;
		// 递归循环
		for (int i = 1; i <= max_choose; i++)
		{
			if (current == (current | 1 << (i - 1)))
				continue;
			if (!DFS_winEASY(current | 1 << (i - 1), max_choose, total - i))
			{
				return true;
			}
		}
		return false;
	}





	bool DFS_win(unordered_map<int, bool> &status, int current, int &max_choose, int total)
	{
		if (total <= 0)
			return false;
		//hashmap中如果存在current(之前访问过)，就直接问返回对应的值
		if (status.find(current) != status.end())
			return status[current];
		// 递归循环
		for (int i = 1; i <= max_choose; i++)
		{
			if (current == (current | 1 << (i - 1)))
				continue;
			if (!DFS_win(status, current | 1 << (i - 1), max_choose, total - i))
			{
				status[current] = true;
				return true;
			}
		}
		status[current] = false;
		return status[current];
	}
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
			return false;
		if (desiredTotal <= 0)
			return true;
		unordered_map<int, bool> status;
		int current = 0;
		return DFS_win(status, current, maxChoosableInteger, desiredTotal);

	}



};