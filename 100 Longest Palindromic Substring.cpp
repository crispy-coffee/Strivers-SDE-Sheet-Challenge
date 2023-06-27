#include<bits/stdc++.h>
/*
bool check(string& str){
    int i=0, j=str.size()-1;
    while(i<=j){
        if(str[i++] != str[j--])
            return false;
    }
    return true;
}

string longestPalinSubstring(string& str)
{    
    int n = str.size();
    if(n==0) return "";
    string ans = "";
    ans += str[0];
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            string temp = str.substr(i,j-i+1);
            if(check(temp)){
                if(temp.size()>ans.size()){
                    ans = temp;
                }
            }
        }
    }
    return ans;
}
*/

string longestPalinSubstring(string& str){
    int n = str.length();
    int l, r;
    int start = 0;
    int end = 1;

    for (int i = 1; i < n; i++) {
        // Even-length substring
        l = i - 1;
        r = i;

        while (l >= 0 && r < n && str[l] == str[r]) {
            if (r - l + 1 > end) {
                start = l;
                end = r - l + 1;
            }
            l--;
            r++;
        }

        // Odd-length substring
        l = i - 1;
        r = i + 1;

        while (l >= 0 && r < n && str[l] == str[r]) {
            if (r - l + 1 > end) {
                start = l;
                end = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return str.substr(start, end);
}

