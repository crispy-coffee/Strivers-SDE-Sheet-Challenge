#include <bits/stdc++.h> 

int Recursion(int index, int prev, vector<int>& rack){

	if(index == rack.size())
		return 0;
	
	int include = 0, exlcude = 0;
	if(prev == -1 || rack[prev] < rack[index])
		include = rack[index] + Recursion(index+1, index, rack);
	exlcude = Recursion(index+1, prev, rack);
	return max(include, exlcude);
}

int Memoization(int index, int prev, vector<int>& rack, vector<vector<int>>& dp){

	if(index == rack.size())
		return 0;
	
	if(dp[index][prev+1] != -1)
		return dp[index][prev+1];

	int include = 0, exlcude = 0;
	if(prev == -1 || rack[prev] < rack[index])
		include = rack[index] + Memoization(index+1, index, rack, dp);
	exlcude = Memoization(index+1, prev, rack, dp);
	return dp[index][prev+1] = max(include, exlcude);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{	
	// 1 Recursion
	// return Recursion(0, -1, rack);

	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return Memoization(0, -1, rack, dp);

}