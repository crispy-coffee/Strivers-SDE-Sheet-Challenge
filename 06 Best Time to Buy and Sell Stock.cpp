#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    vector<int> leaknews(n);
    leaknews[n-1] = prices[n-1];
    for(int i=n-2; i>=0; i--){
        leaknews[i] = max(leaknews[i+1], prices[i]);
    }

    int profit = 0;
    for(int i=0; i<n; i++){
        profit = max(profit, leaknews[i]-prices[i]);
    }

    return profit;
}