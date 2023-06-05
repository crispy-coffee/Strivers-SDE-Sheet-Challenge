#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    
    long long ans = 0;
    long long curr = 0;
    for(long long i=0; i<n; i++){
        curr += arr[i];
        ans = max(curr, ans);
        if(curr<0) curr = 0;
    }
    return ans;
}