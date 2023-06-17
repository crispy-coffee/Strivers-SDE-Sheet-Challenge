#include <bits/stdc++.h> 

bool painting(vector<int>& graph, vector<int>& color, int newcolor){
    for(auto i:graph){
        if(color[i] == newcolor)
            return false;
    }
    return true;
}

string Recursion(unordered_map<int,vector<int>> &adj, vector<int> &color, int node, int m){

    if(node == adj.size()) return "YES";

    for(int c=1; c<=m; c++){
        if(painting(adj[node], color, c)){
            color[node] = c;
            if(Recursion(adj, color, node+1, m) == "YES") return "YES";
            color[node] = 0;
        }
    }
    return "NO";
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    unordered_map<int,vector<int>> adj;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){
            if(mat[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> color(mat.size()+1, 0);

    return Recursion(adj, color, 0, m);

}