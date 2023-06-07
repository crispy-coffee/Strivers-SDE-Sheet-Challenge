#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	
	map<int,int> count;	
	for(int i=0; i<n; i++){
		count[arr[i]]++;
	}
	
	int vote = floor(n/2);
	for(auto i:count){
		if(i.second > vote)
			return i.first;
	}

	return -1;
}