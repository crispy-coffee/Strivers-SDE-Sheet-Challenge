#include<bits/stdc++.h>
bool dfs(int curr, int parent, unordered_map<int,vector<int>>& adj, 
vector<bool>& visited){

    visited[curr] = true;

    for(auto child:adj[curr]){
        if(visited[child] == false){
            if(dfs(child, curr, adj, visited)) return true;
        }else if (child != parent){
            return true;
        }
    }
    // visited[curr] = false;
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,vector<int>> adj;
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<bool> visited(n+1,false);
    for(int i=1; i<=n; i++){
        if(visited[i] == false){
            if(dfs(i, -1, adj, visited)) return "Yes";
        }
    }
    return "No";
}
