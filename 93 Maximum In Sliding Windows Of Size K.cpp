#include <bits/stdc++.h> 

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> result;
    priority_queue<pair<int,int>> p;
    int end=0;
    int n = nums.size();

    for(end; end<k; end++){
        p.push({nums[end],end});
    }

    result.push_back(p.top().first);
    for(end; end<nums.size(); end++){
        p.push({nums[end],end});
        while(p.top().second<=end-k)
            p.pop();

        result.push_back(p.top().first);
    }

    return result;
}