#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

	sort(begin(arr), end(arr));
	set<vector<int>> st;
	vector<vector<int>> result;

	for(int i=0; i<n-2; i++){
		int start=i+1, end=n-1;
		int newtarget = K-arr[i];
		while(start<end){
			if(arr[start]+arr[end] == newtarget){
				st.insert({arr[i],arr[start],arr[end]});
				start++;
				end--;
			}else if(arr[start] + arr[end] < newtarget){
				start++;
			}else{
				end--;
			}
		}
	}

	for(auto i:st){
		result.push_back(i);
	}

	return result;
}