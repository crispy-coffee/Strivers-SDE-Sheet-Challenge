#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans = {{1}};
    if (n == 1)
        return ans;
    ans.push_back({1, 1});

    for (int i = 1; i < n - 1; i++)
    {
        vector<long long int> temp = {1};
        for (int j = 1; j < ans[i].size(); j++)
        {
            temp.push_back(ans[i][j - 1] + ans[i][j]);
        }
        temp.push_back(1);

        ans.push_back(temp);
    }

    return ans;
}
