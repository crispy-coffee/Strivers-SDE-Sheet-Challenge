#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    // Write your code here.
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            int k=j+1, l=n-1;
            while(k<l){
                int value = target - arr[i] - arr[j];
                if(arr[k]+arr[l]==value){
                    return "Yes";
                }else if(arr[k]+arr[l]<value){
                    k++;
                }else{
                    l--;
                }
            }
        }
    }
    return "No";
}
