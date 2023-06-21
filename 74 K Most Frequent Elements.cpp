#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    map<int,int> m;
    for(auto i:arr){
        m[i]++;
    }

    vector<pair<int,int>> p;

    for(auto i:m){
        p.push_back({i.second,i.first});
    }
    sort(p.begin(),p.end(), [&](pair<int,int>&a, pair<int,int>&b){
        return a.first > b.first;
    });
    vector<int> ans;

    for(int i=0; i<k; i++){
        ans.push_back(p[i].second);
    }
    sort(ans.begin(), ans.end());
    return ans;
}