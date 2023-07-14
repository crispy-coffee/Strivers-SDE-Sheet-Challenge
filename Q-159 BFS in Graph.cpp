#include <bits/stdc++.h> 

void bfs(int parent, unordered_map<int,vector<int>>& adj, vector<bool>& visited, vector<int>& result){

    visited[parent] = true;

    queue<int> q;
    q.push(parent);
    while(!q.empty()){

        int top = q.front();
        q.pop();
        for(int child:adj[top]){
            if(visited[child] == false){
                visited[child] = true;
                result.push_back(child);
                q.push(child);
            }
        }

    }

}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,vector<int>> adj;
    for(auto i:edges){
        int u = i.first;
        int v = i.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto &i:adj){
        sort(begin(i.second), end(i.second));
    }

    vector<bool> visited(vertex);
    vector<int> result;
    for(int i=0; i<vertex; i++){
        if(visited[i] == false){
            result.push_back(i);
            bfs(i, adj, visited, result);
        }
    }
    return result;
}