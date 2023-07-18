#include <bits/stdc++.h> 

bool Recursion(vector<int>& arr, int index, int k){
    if(k == 0)
        return true;
    
    if(k<0)
        return false;
    
    if(index == arr.size())
        return false;
    
    bool include = Recursion(arr, index+1, k-arr[index]);
    bool exclude = Recursion(arr, index+1, k);

    return (include or exclude);
}

bool Memoization(vector<int>& arr, int index, int k, vector<vector<int>>& dp){
    if(k == 0)
        return true;
    
    if(k<0)
        return false;

    if(index == arr.size())
        return false;
    
    if(dp[index][k] != -1)
        return dp[index][k];

    bool include = Memoization(arr, index+1, k-arr[index], dp);
    bool exclude = Memoization(arr, index+1, k, dp);

    return dp[index][k] = (include or exclude);
}


bool subsetSumToK(int n, int k, vector<int> &arr) {

    // 1 Recursion
    // return Recursion(arr, 0, k);

    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return Memoization(arr, 0, k, dp);
}