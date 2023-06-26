#include <bits/stdc++.h>

vector<int> maxMinWindow(vector<int> a, int n) {
    //Brute Force
    /*
    vector<int> storage;
    for (int i = 1; i <= n; i++) {
        int maxi = INT_MIN;
        for (int j = 0; j <= n - i; j++) {
            int mini = INT_MAX;
            for (int k = j; k < j + i; k++) {
                mini = min(mini, a[k]);
            }
            maxi = max(mini, maxi);
        }
        storage.push_back(maxi);
    }
    return storage;
    */

    //Optimal Approach
    stack<int> stk;
    vector<int> left(n), right(n), ans(n, INT_MIN);
    left[0] = -1;
    stk.push(0);

    for (int i = 1; i < n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }

    while (!stk.empty()) {
        stk.pop();
    }

    right[n - 1] = n;
    stk.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }

    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len - 1] = max(ans[len - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}
