#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> merge;
    merge.push_back(intervals[0]);

    for(int i=1; i<n; i++){

        if(merge.back()[1] >= intervals[i][0]){
            merge.back()[1] = max(merge.back()[1], intervals[i][1]);
        }else{
            merge.push_back(intervals[i]);
        }
    }

    return merge;

}
