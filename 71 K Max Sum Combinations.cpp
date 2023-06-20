#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// TLE
	/*
	vector<long long> totalsum;
	for(auto i:a){
		for(auto j:b){
			totalsum.push_back(i+j);
		}
	}
	sort(begin(totalsum), end(totalsum));
	long long size = totalsum.size()-1;
	vector<int> answer;
	for(int i=0; i<k; i++){
		answer.push_back(totalsum[size--]);
	}
	return answer;
	*/


	vector<int> answer;
	priority_queue<int> p;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			p.push(a[i]+b[j]);
		}
	}

	for(int i=0; i<k; i++){
		answer.push_back(p.top());
		p.pop();
	}
	return answer;

}