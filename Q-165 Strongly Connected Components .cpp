#include<bits/stdc++.h>
void dfs(int index, vector<bool>& visited, unordered_map<int,vector<int>>& adj, stack<int>& st){
    
    visited[index] = true;
    for(auto child:adj[index]){
        if(visited[child] == false)
            dfs(child, visited, adj, st);
    }

    st.push(index);
}

void revdfs(int index, vector<bool>& visited, unordered_map<int,vector<int>>& revadj, vector<int>& temp){

    visited[index] = true;
    temp.push_back(index);
    for(auto child:revadj[index]){
        if(visited[child] == false)
            revdfs(child, visited, revadj, temp);
    }

}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{   
    /*
    1 Create adjacency list
    2 Create Topological sort in stack
    3 Now stack is in reverse order, so transpose the adjacency list
    4 Now call as per the adjacency list with visited[top] == false
    5 During call increase count
    */
    // if(edges.size() == 0)
        // return {{0}};
    unordered_map<int, vector<int>> adj, revadj;

    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(n,false);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(visited[i] == false){
            dfs(i, visited, adj, st);
        }
    }

    for(int i=0; i<n; i++){
        visited[i] = false;
        for(auto j:adj[i]){
            revadj[j].push_back(i);
        }
    }

    vector<vector<int>> graph;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(visited[top] == false){
            vector<int> temp;
            revdfs(top, visited, revadj, temp);
            graph.push_back(temp);
        }
    }
    return graph;
}