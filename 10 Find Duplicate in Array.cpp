#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	int i=0, next = 0;
	while(arr[i] != -1){
		next = arr[i];
		arr[i] = -1;
		i = next;
	}

	return next;
	
}
