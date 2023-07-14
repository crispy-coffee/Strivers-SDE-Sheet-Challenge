#include<bits/stdc++.h>

bool check(int start, vector<int> &colored, unordered_map<int,vector<int>>& adj){
	queue<int> q;
	q.push(start);
	colored[start] = 0;

	while(!q.empty()){

		int top = q.front();
		q.pop();

		for(auto child:adj[top]){

			if(colored[child] == -1){
				colored[child] = !colored[top];
				q.push(child);
			}else if(colored[child] == colored[top]){
				return false;
			}
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {

	unordered_map<int,vector<int>> adj;
	for(int i=0; i<edges.size(); i++){
		for(int j=0; j<edges[0].size(); j++){
			if(edges[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> colored(edges.size(), -1);
	for(int i=0; i<edges.size(); i++){
		if(colored[i] == -1){
			if(check(i, colored, adj) == false){
				return false;
			}
		}
	}
	return true;

}