#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    // 1 Brute Force
    /*
    int maxi = 1;
    int n = input.size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            set<char> st;
            for(int k=i; k<=j; k++){
                st.insert(input[k]);
            }
            if(st.size() == j-i+1){
                maxi = max(maxi, j-i+1);
            }
        }
    }
    return maxi;
    */  

    // 2 Optimal Approach
    int start = 0, end = 0;
    unordered_set<char> st;
    int maxi = 1;
    while(end<input.size()){
        
        if(st.find(input[end]) == st.end()){
            st.insert(input[end]);
            end++;
            maxi = max(maxi, end-start);
        }else{
            st.erase(input[start]);
            start++;
        }
    }
    return maxi;




}