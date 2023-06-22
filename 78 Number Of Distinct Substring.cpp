#include <bits/stdc++.h> 
int distinctSubstring(string &i) {
    //  Write your code here.
    unordered_set<string> container;

    for(int j=0; j<i.size(); j++){
        for(int k=j; k<i.size(); k++){
            container.insert(i.substr(j,k-j+1));
        }
    }

    
    return container.size();

}
