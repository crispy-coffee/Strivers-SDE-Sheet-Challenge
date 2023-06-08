#include <bits/stdc++.h>

int zero(vector<int>& temp){
  long long sum = 0;
  for(auto i:temp){
    sum+=i;
  }

  if(sum == 0)
    return temp.size();
  return -1;
}

int LongestSubsetWithZeroSum(vector<int> arr) {

  // Write your code here
  int n = arr.size();
  int maxi = 0;
  // 1 bruteforce
  /*
  for(int i=0; i<n ;i++){
    vector<int> temp;
    for(int j=i; j<n; j++){
      temp.push_back(arr[j]);
      maxi = max(maxi, zero(temp));
    }
  }
  return maxi;
  */
  int sum = 0;
  unordered_map<int,int> aunty;
  for(int i=0; i<n; i++){
    sum += arr[i];  
    if(sum==0){
      maxi = max(maxi, i+1);
    }else{
      if(aunty.count(sum)){
        maxi = max(maxi, i-aunty[sum]);
      }else{
        aunty[sum] = i;
      }
    }

  }

  return maxi;
}