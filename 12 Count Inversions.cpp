#include <bits/stdc++.h> 
#define ll long long 
long long getInversions(long long *arr, int n){
    // Write your code here.
    ll pairs = 0;

    for(ll i=0; i<n; i++ ){
        for(ll j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                pairs++;
            }
        }
    }

    return pairs;
}