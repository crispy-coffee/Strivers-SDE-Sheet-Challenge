#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,vector<int>> adj;

    vector<int> indegree(n+1);
    for(auto i:edges){
        adj[i.first].push_back(i.second);
        indegree[i.second]++;

    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    int ans=0;

    while(!q.empty()){
        int node = q.front();

        for(auto neighbour : adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
        
        q.pop();

      ans++;

    }

    if(ans == n) return false;
    return true;
}