#include <bits/stdc++.h> 

int Recursion(vector<vector<int>>& grid, int i, int j){
    if(i==grid.size()-1 and j==grid[0].size()-1)
        return grid[i][j];
    
    if( i>=grid.size() or j>= grid[0].size())
        return INT_MAX;

    int down = Recursion(grid, i+1, j);
    int right = Recursion(grid, i, j+1);

    return min(down, right) + grid[i][j];
}

int Memoization(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    if(i==grid.size()-1 and j==grid[0].size()-1)
        return grid[i][j];
    
    if( i>=grid.size() or j>= grid[0].size())
        return INT_MAX;

    if(dp[i][j] != -1)
        return dp[i][j];

    int down = Memoization(grid, i+1, j, dp);
    int right = Memoization(grid, i, j+1, dp);

    return dp[i][j] = min(down, right) + grid[i][j];
}

int minSumPath(vector<vector<int>> &grid) {
    // 1 Recursion
    // return Recursion(grid, 0, 0);

    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return Memoization(grid, 0, 0, dp);
}