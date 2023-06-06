#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	// Write your code here.
	//1 Using Sort
	/*
	int i=m;
	for(auto j:nums2){
		nums1[i] = j;
		i++;
	}

	sort(nums1.begin(), nums1.end());
	return nums1;
	*/

	//2 Optimial Approach
	int index = m+n-1;
	int i=m-1, j=n-1;
	while(i>=0 || j>=0){

		if(i>=0 and j>=0 and nums1[i]>nums2[j]){
			nums1[index] = nums1[i];
			index--;
			i--;
		}else if(i>=0 and j>=0 and nums1[i]<=nums2[j]){
			nums1[index] = nums2[j];
			index--;
			j--;
		}else if(i>=0){
			nums1[index] = nums1[i];
			index--;
			i--;
		}else{
			nums1[index] = nums2[j];
			index--;
			j--;
		}
	}
	return nums1;

}