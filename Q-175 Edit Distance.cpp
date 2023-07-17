#include<bits/stdc++.h>
int Recursion(string& str1, string& str2, int i, int j){

    if(i==str1.size())
        return str2.size()-j;
    
    if(j==str2.size())
        return str1.size()-i;

    int ans = 0;
    if(str1[i] == str2[j]){
        ans = Recursion(str1, str2, i+1, j+1);
    }else{
        int insertans = 1 + Recursion(str1, str2, i, j+1);
        int deleteans = 1 + Recursion(str1, str2, i+1, j);
        int replaceans = 1 + Recursion(str1, str2, i+1, j+1);
        ans = min({insertans, deleteans, replaceans}) ;
    }
    return ans;
}

int Memoization(string& str1, string& str2, int i, int j, vector<vector<int>>& dp){

    if(i==str1.size())
        return str2.size()-j;
    
    if(j==str2.size())
        return str1.size()-i;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(str1[i] == str2[j]){
        ans = Memoization(str1, str2, i+1, j+1, dp);
    }else{
        int insertans = 1 + Memoization(str1, str2, i, j+1, dp);
        int deleteans = 1 + Memoization(str1, str2, i+1, j, dp);
        int replaceans = 1 + Memoization(str1, str2, i+1, j+1, dp);
        ans = min({insertans, deleteans, replaceans}) ;
    }
    return dp[i][j] = ans;
}


int editDistance(string str1, string str2)
{
    // 1 Recursion
    // return Recursion(str1, str2, 0, 0);

    // 2 memoization
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size(), -1));
    return Memoization(str1, str2, 0, 0, dp);
}