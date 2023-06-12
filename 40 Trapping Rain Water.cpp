#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    // Write your code here.
    // long n = height.size();
    vector<long> left(n),right(n);
    left[0] = height[0];

    for(long i=1; i<n; i++){
        left[i] = max(left[i-1],height[i]);
    }

    right[n-1] = height[n-1];
    for(long i=n-2; i>=0; i--){
        right[i] = max(right[i+1],height[i]);
    }
    
    long ans=0;
    for(long i=0; i<n; i++){
        ans += min(left[i],right[i])-height[i];
    }
    return ans;
}