#include <bits/stdc++.h>
struct Meeting
{
    int start;
    int end;
    int pos;
};

static bool compartator(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    Meeting a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].start = start[i];
        a[i].end = end[i];
        a[i].pos = i + 1;
    }
    sort(a, a + n, compartator);
    vector<int> ans;
    int endd = a[0].end;
    ans.push_back(a[0].pos);
    for (int i = 1; i < n; i++)
    {
        if (a[i].start > endd)
        {
            endd = a[i].end;
            ans.push_back(a[i].pos);
        }
    }
    return ans;
}