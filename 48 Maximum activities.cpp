#include<bits/stdc++.h>

bool cmp(pair<int,int> &a, pair<int,int> &b ){
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> meet;
    int n = start.size();
    for(int i=0; i<n; i++){
        meet.push_back({start[i], finish[i]});
    }

    sort(begin(meet), end(meet), cmp);

    int ans = 1;
    int prev = meet[0].second;
    for(int i=1; i<n; i++){
        if(prev <= meet[i].first){
            ans++;
            prev = meet[i].second;
        }
    }
    return ans;

}