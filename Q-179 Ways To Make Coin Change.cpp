
#include<bits/stdc++.h>

long Recursion(int *coins, int index, int n, int value){
    if(value<0)
        return LONG_MIN;

    if(value == 0)
        return 1;
    
    long ans = LONG_MIN, maxi=0;
    for(long i=index; i<n; i++){
        ans = Recursion(coins, i, n, value-coins[i]);

        if(ans != LONG_MIN)
            maxi += ans;

    }   
    return maxi;
}

long Memoization(int *coins, int index, int n, int value, vector<vector<long>>& dp){
    if(value<0)
        return LONG_MIN;

    if(value == 0)
        return 1;
    
    if(dp[index][value] != -1)
        return dp[index][value];
    
    long ans = LONG_MIN, maxi=0;
    for(long i=index; i<n; i++){
        ans = Memoization(coins, i, n, value-coins[i], dp);

        if(ans != LONG_MIN)
            maxi += ans;

    }   
    return dp[index][value] = maxi;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{   
    // 1 Recursion
    // return Recursion(denominations, 0, n, value);

    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return Memoization(denominations, 0, n, value, dp);
}