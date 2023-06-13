int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    // TLE
    /*
    int maxi = 0;
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=i; j<n; j++){
            if(arr[j]){
                count++;
            }
            if((j-i+1)-count <= k)
                maxi = max(maxi, j-i+1);
        }
    }
    return maxi;
    */

    int i=0;
    int j=0;
    for(j=0; j<n; j++){
        if(arr[j]==0) k--;

        if(k<0 and arr[i++]==0) k++;
    }
    return j-i;
}
