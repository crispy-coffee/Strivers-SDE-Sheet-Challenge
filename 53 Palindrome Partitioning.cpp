#include <bits/stdc++.h> 

vector<vector<string>> answer;
vector<string> temp;

bool ispalidrome(string &s, int start, int end){
    while(start<=end){
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void Recursion(int index, string &s){

    if(index == s.size()){
        answer.push_back(temp);
        return;
    }

    for(int i=index; i<s.size(); i++){
        
        if(ispalidrome(s, index, i)){
            temp.push_back(s.substr(index, i-index+1));
            Recursion(i+1, s);
            temp.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    Recursion(0, s);
    return answer;
}