#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{   
    vector<int> result;
    unordered_map<int,int> count;
    int i=0;
    for(int j=0; j<arr.size(); j++){
        count[arr[j]]++;

        if(j>=k-1){
            result.push_back(count.size());
            count[arr[i]]--;
            if(count[arr[i]] == 0){
                count.erase(arr[i]);
            }
            i++;
        }

    }
    
    return result;
}
