#include <bits/stdc++.h>

void change(vector<vector<int>>& matrix, int i, int j){
	
	for(int index=0; index<matrix[0].size(); index++){
		matrix[i][index] = 0;
	}

	for(int index=0; index<matrix.size(); index++){
		matrix[index][j] = 0;
	}

}

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	vector<pair<int,int>> place;
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size(); j++){
			if(matrix[i][j] == 0){
				place.push_back({i,j});
			}
		}
	}

	for(auto i:place){
		change(matrix, i.first, i.second);
	}

}