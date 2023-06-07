#include <bits/stdc++.h> 

// 1 Recursion
int Recursion(int i, int j, int m, int n){
	if(i>=m or j>=n)
		return 0;
	if(i==m-1 and j==n-1)
		return 1;
	
	int right = Recursion(i, j+1, m, n);
	int down = Recursion(i+1, j, m, n);

	return right+down;
}

// 2 Recursion With Memoization
int Memoization(int i, int j, int m, int n, vector<vector<int>>& dp){
	if(i>=m or j>=n)
		return 0;
	if(i==m-1 and j==n-1)
		return 1;
	
	if(dp[i][j] != -1)
		return dp[i][j];

	int right = Memoization(i, j+1, m, n, dp);
	int down = Memoization(i+1, j, m, n, dp);

	return dp[i][j] = right+down;
}

int uniquePaths(int m, int n) {
	// Write your code here.
	// 1 Recursion
	// return Recursion(0, 0, m, n);

	// 2 Recursion WIth Memoization
	vector<vector<int>> dp(m, vector<int>(n,-1));
	return Memoization(0, 0, m, n, dp);
}