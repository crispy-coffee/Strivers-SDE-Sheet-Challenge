void dfs(int parent, unordered_map<int,vector<int>>& adj, vector<bool>& visited, vector<vector<int>>& result){
 
    visited[parent] = true;

    for(auto child:adj[parent]){
        if (visited[child] == false) {
            result.back().push_back(child);
            dfs(child, adj, visited, result);
        }
    }

}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,vector<int>> adj;
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    vector<bool> visited(V);
    vector<vector<int>> result;
    for(int i=0; i<V; i++){
        if(visited[i] == false){
            result.push_back({i});
            dfs(i, adj, visited, result);
        }
    }

    return result;
}