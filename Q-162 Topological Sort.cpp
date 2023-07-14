#include <bits/stdc++.h> 

vector<int> bfs(vector<vector<int>> &edges, int v, int e){
    unordered_map<int,vector<int>> adj;

    vector<int> indegree(v);
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        indegree[i[1]]++;

    }

    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while(!q.empty()){
        int node = q.front();


        for(auto neighbour : adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
        q.pop();
        ans.push_back(node);
    }

    return ans;
}

void dfs(int index, vector<bool>& visited, unordered_map<int,vector<int>>& adj, stack<int>& st){

    visited[index] = true;
    for(auto child:adj[index]){
        if(visited[child] == false){
            dfs(child, visited, adj, st);
        }
    }
    st.push(index);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // 1 bfs
    // return bfs(edges, v, e);

    unordered_map<int,vector<int>> adj;
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(v, false);
    stack<int> st;
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            dfs(i, visited, adj ,st);
        }
    }

    vector<int> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    return result;
}