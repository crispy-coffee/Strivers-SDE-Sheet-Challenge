#include <bits/stdc++.h> 

void anderdaaldo(vector<int>& heap, int value){

    int n = heap.size();

    for(int i=0; i<n; i++){
        if(value<=heap[i]){
            heap.insert(heap.begin()+i, value);
            return;
        }
    }
    heap.push_back(value);
}


vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    vector<int> answer;
    for(int i=0; i<q.size(); i++){
        if(q[i][0] == 0){
            anderdaaldo(heap, q[i][1]);

        }else{
            answer.push_back(heap.front());
            heap.erase(heap.begin());
        }
    }
    return answer;
}
