#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    map<int,int> count;	
	for(int i=0; i<n; i++){
		count[arr[i]]++;
	}
	
	int vote = n/3;
    vector<int> answer;
	for(auto i:count){
		if(i.second > vote)
            answer.push_back(i.first);
	}

	return answer;
}