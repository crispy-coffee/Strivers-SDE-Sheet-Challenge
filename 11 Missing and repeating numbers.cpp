#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{	
	sort(arr.begin(), arr.end());
	// Write your code here 
	int missing = -1, repeating = -1;
	long long sum = arr[0];
	for(int i=1; i<n; i++){
		sum += arr[i];

		if(arr[i] == arr[i-1])
			repeating = arr[i];
	}

	missing = (n*(n+1)/2) - (sum - repeating);
	return {missing, repeating};
}
