#include <bits/stdc++.h>
class Kthlargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int gk;
    Kthlargest(int k, vector<int> &arr)
    {
        gk = k;
        for (auto a : arr)
        {
            if (pq.size() < k)
                pq.push(a);
            else if (pq.size() == k && a >= pq.top())
                pq.push(a);
            if (pq.size() > k)
                pq.pop();
        }
    }

    void add(int num)
    {
        if (pq.size() < gk)
            pq.push(num);
        else if (pq.size() == gk && num >= pq.top())
            pq.push(num);
        if (pq.size() > gk)
            pq.pop();
    }

    int getKthLargest() { 
        return pq.top(); 
        }
};