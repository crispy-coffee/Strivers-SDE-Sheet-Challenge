#include <bits/stdc++.h>

void findSubsetSum(vector<int> &num, int i, int n, vector<int> &res, int sum)
{
    if (i >= n)
    {
        res.push_back(sum);
        return;
    }
    findSubsetSum(num, i + 1, n, res, sum + num[i]);
    findSubsetSum(num, i + 1, n, res, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n = num.size();
    vector<int> res;
    int sum = 0;
    findSubsetSum(num, 0, n, res, sum);
    sort(res.begin(), res.end());
    return res;
}