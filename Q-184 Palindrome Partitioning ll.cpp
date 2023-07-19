#include <bits/stdc++.h> 

bool palidrome(int start, int end, string& s){
    while(start<=end){
        if(s[start++]!=s[end--])
            return false;
        
        // start++;
        // end--;
    }
    return true;
}

int Memoization(string& s, int index, vector<int>& dp){
    if(index == s.size())
        return 0;
    
    if(dp[index] != -1)
        return dp[index];

    int mini = INT_MAX;
    for(int j=index; j<s.size(); j++){
        if(palidrome(index, j, s)){
            int ans = Memoization(s, j+1, dp);
            mini = min(mini, ans+1);
        }
    }

    return dp[index] = mini;
}

int palindromePartitioning(string str) {
    vector<int>dp (str.size(), -1);
    return Memoization(str, 0, dp)-1;
}
