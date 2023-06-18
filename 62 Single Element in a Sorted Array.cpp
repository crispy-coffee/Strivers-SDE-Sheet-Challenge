int singleNonDuplicate(vector<int>& arr)
{
	// TLE
	/*
	int xo = 0;
	for(int i=1; i<arr.size(); i++){
		if(arr[i-1] != arr[i]){
			return arr[i-1];
		}
		i++;
	}
	return arr[arr.size()-1];
	*/
	int n = arr.size();
	int start = 0, end = n-1;	

	while(start<= end){
		int mid = start + (end-start)/2;
		if(mid == 0 and arr[mid] != arr[mid+1]){
			return arr[mid];
		}else if(mid == n-1 and arr[mid] != arr[mid-1]){
			return arr[mid];
		}else if(arr[mid-1] != arr[mid] and arr[mid] != arr[mid+1]){
			return arr[mid];
		}else if((arr[mid] == arr[mid+1]) or arr[mid] == arr[mid-1]){
			if(arr[mid] == arr[mid+1]){
				if(mid%2==0){
					start = mid+1;
				}else{
					end = mid-1;
				}
			}else{
				if(mid%2==1){
					start = mid+1;
				}else{
					end = mid-1;
				}
			}
		}

	}

	return -1;
}