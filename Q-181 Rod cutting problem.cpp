#include<bits/stdc++.h>

int Recursion(vector<int>& price, int index, int value){
    if(value == 0)
        return 0;

    if(value<0 or index==price.size())
        return INT_MIN;
    
    int ans = 0, maxi=0;
    for(int i=index; i<price.size(); i++){
        ans = Recursion(price, i, value-(i+1)) + price[i];

        maxi = max(maxi, ans);
    }   
	
    return maxi;
}


int Memoization(vector<int>& price, int index, int value, vector<vector<int>>& dp){
    if(value == 0)
        return 0;

    if(value<0 or index==price.size())
        return INT_MIN;
    
	if(dp[index][value] != -1)
		return dp[index][value];

    int ans = 0, maxi=0;
    for(int i=index; i<price.size(); i++){
        ans = Memoization(price, i, value-(i+1), dp) + price[i];

        maxi = max(maxi, ans);
    }   
	
    return dp[index][value] = maxi;
}


int cutRod(vector<int> &price, int n)
{	
	// 1 Recursion
	// return Recursion(price, 0, n);

	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return Memoization(price, 0, n, dp);
}
