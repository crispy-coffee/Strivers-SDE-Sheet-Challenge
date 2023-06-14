#include <bits/stdc++.h> 

bool cmp(pair<double,int>&a, pair<double,int>&b ){
    return a.first>b.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    vector<pair<double,int>> store(n);

    for(int i=0; i<n; i++){
        store[i] = {((double)items[i].second/items[i].first),i};
    }

    sort(store.begin(),store.end(), cmp);
    double ans = 0;

    for(int i=0; i<store.size() and w; i++){
        int index = store[i].second;
        if(items[index].first <= w){
            ans += items[index].second;
            w -= items[index].first;
        }else{
            ans += store[i].first * w;
            w -= w;
        }
    }

    return ans;
}