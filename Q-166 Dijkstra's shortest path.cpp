#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> distance(vertices, INT_MAX);
    for(auto i:vec){
        adj[i[0]].push_back({i[1], i[2]});
        adj[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> st; //->distance and node
    st.push({source, 0});
    distance[source] = 0;

    while(!st.empty()){

        auto top = st.top();
        st.pop();
        int dis = top.first;
        int node = top.second;

        for(auto child:adj[node]){
            if(distance[child.first] > child.second + dis){
                distance[child.first] = child.second + dis;
                st.push({distance[child.first], child.first});
            }
        }
    }

    return distance;

}
