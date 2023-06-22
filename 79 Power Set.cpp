#include <bits/stdc++.h> 
vector<vector<int>>st;

void recursion(vector<int>&v, int index, vector<int>temp){
    if(index == v.size()){
        st.push_back(temp);
        return;
    }

    recursion(v, index+1, temp);
    temp.push_back(v[index]);
    recursion(v, index+1, temp);

}

vector<vector<int>> pwset(vector<int>v)
{
    recursion(v, 0, {});
    return st;

}