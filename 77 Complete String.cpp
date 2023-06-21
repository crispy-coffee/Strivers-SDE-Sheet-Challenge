#include <bits/stdc++.h> 
string completeString(int n, vector<string> &a){
    // Write your code here.
    unordered_map<string,bool> joint;

    for(auto i:a){
        joint[i] = true;
    }

    vector<string> answer;

    for(int i=0; i<n; i++){
        bool valid = true;
        for(int j=0; j<a[i].size(); j++){
            if(joint.find(a[i].substr(0,j+1)) == joint.end()){
                valid = false;
                break;
            }
        }
        if(valid){
            answer.push_back(a[i]);
        }
    }
    
    sort(begin(answer), end(answer), [&](string& a, string& b){
        if(a.size() == b.size()){
            return a<b;
        }
        return a.size()>b.size();
    });

    if(answer.size() == 0){
        return "None";
    }
    return answer[0];

}   