#include <bits/stdc++.h> 

int smallest(vector<vector<int>>& arr, vector<int>& index){
    int value = INT_MAX, idx = -1;
    for(int i=0; i<arr.size(); i++){
        if(index[i]<arr[i].size()){
            if(value > arr[i][index[i]]){
                value = arr[i][index[i]];
                idx = i;
            }
        }
    }
    
    if(idx != -1)
        index[idx]++;
    return value;
}


vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Bruteforce Approach
    /*
    vector<int> answer;
    for(auto i:kArrays){
        answer.insert(answer.end(),i.begin(),i.end());
    }

    sort(answer.begin(),answer.end());
    return answer;
    */

    vector<int> answer;
    vector<int> index(k,0);
    while(true){

        int value = smallest(arr, index);
        if(value == INT_MAX) break;
        answer.push_back(value);
    }
    return answer;

}
