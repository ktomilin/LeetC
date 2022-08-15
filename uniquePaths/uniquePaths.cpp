// uniquePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?
//Note : m and n will be at most 100.
//
//	Example 1 :
//
//	Input : m = 3, n = 2
//	Output : 3
//	Explanation :
//	From the top - left corner, there are a total of 3 ways to reach the bottom - right corner :
//1. Right->Right->Down
//2. Right->Down->Right
//3. Down->Right->Right
//Example 2 :
//
//	Input : m = 7, n = 3
//	Output : 28


#include <iostream>
#include <vector>

int memo[101][101] = { -1 };

int uniquePaths(int m, int n)
{
	if ((1 == m && 2 == n) || (2 == m && 1 == n) || (1 == m && 1 == n)) return 1;
	if (m <= 0 || n <= 0) return 0;
	if (memo[m][n] >= 0) return memo[m][n];
	memo[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	return memo[m][n];
}


void testUniquePaths()
{
	int res = uniquePaths(3, 2);
	_ASSERTE( 3 == res);

	res = uniquePaths(7, 3);
	_ASSERTE(28 == res);

	res = uniquePaths(1, 1);
	_ASSERTE(1 == res);

	res = uniquePaths(10, 10);
	_ASSERTE(48620 == res);

	res = uniquePaths(19, 13);
	_ASSERTE(86493225 == res);
} 

int main()
{
	testUniquePaths();
}

