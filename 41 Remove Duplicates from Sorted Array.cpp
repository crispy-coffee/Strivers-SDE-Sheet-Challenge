int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int index = 0;
	for(int i=0; i<n-1; i++){
		if(i<n and arr[i] == arr[i+1]){
			continue;
		}else{
			arr[index] = arr[i];
			index++;
			continue;
		}
	}
	
	arr[index] = arr[n-1];
	index++;
	return index;
}