#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> v;
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            st.push(arr[i]);
            v.push_back(-1);
        } else if (st.top() > arr[i]) {
            v.push_back(st.top());
            st.push(arr[i]);
        } else {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                v.push_back(-1);
                st.push(arr[i]);
            } else {
                v.push_back(st.top());
                st.push(arr[i]);
            }
        }
    }
    
    reverse(v.begin(), v.end());
    return v;
}
