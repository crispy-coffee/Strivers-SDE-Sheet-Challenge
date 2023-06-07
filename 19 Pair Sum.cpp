#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> answer;

   for(int i=0; i<arr.size()-1; i++){
      for(int j=i+1; j<arr.size(); j++){
         if(arr[i]+arr[j] == s){
            if(arr[i]<arr[j])
               answer.push_back({arr[i],arr[j]});
            else
               answer.push_back({arr[j],arr[i]});
         }
      }
   }
   sort(answer.begin(),answer.end());
   return answer;
}