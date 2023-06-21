#include <bits/stdc++.h> 
string completeString(int n, vector<string> &a){
    // Write your code here.
    /*
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
    */

   //Little Optimize
   unordered_map<string,bool> joint;

    for(auto i:a){
        joint[i] = true;
    }

    string answer;

    for(int i=0; i<n; i++){
        bool valid = true;
        for(int j=0; j<a[i].size(); j++){
            if(joint.find(a[i].substr(0,j+1)) == joint.end()){
                valid = false;
                break;
            }
        }
        if(valid){
            
            if(answer.size() == 0){
                answer = a[i];
            }else if(answer.size() == a[i].size()){
                answer = min(answer, a[i]);
            }else if(answer.size()<a[i].size()){
                answer = a[i];
            }

        }
    }

    if(answer.size() == 0){
        return "None";
    }
    return answer;


}   