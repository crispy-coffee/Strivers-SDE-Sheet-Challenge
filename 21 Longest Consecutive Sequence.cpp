#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    unordered_set<int> s;
    for(int num:nums){
        s.insert(num);
    }
    
    int maxi = 0;
    for(int num: s){
        if(s.find(num-1) == s.end()){
            int length = 1;
            while(s.find(num+length) != s.end())
                length++;
            maxi = max(length, maxi);
        }
    }
    return maxi;

}