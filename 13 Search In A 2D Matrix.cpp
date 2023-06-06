bool binary(vector<int>& mat, int target){
    int start = 0, end = mat.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(mat[mid] == target)
            return true;
        else if(target < mat[mid])
            end = mid-1;
        else    
            start = mid+1;
        
        mid = start + (end-start)/2;
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int start = 0, end = mat.size()-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(mat[mid][0] <= target and target <= mat[mid][mat[mid].size()-1]){
            return binary(mat[mid], target);
        }else if(target < mat[mid][0]){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return false;
}