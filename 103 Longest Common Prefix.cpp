string longestCommonPrefix(vector<string> &arr, int n)
{   
    string ans="";
    for(int i=0;i<arr[0].size();i++){
        for(int j=1;j<n;j++){
            if(arr[0][i]!=arr[j][i]){
                return ans;
            }
        }
        ans=ans+arr[0][i];
    }
    return ans;
}