#include <bits/stdc++.h> 
int atoi(string str) {

    int ans = 0;
    for(int i=0; i<str.size(); i++){
        int num = str[i]-'0';
        if(0 <= num and num <= 9){
            ans = ans*10 + num;
        }
    }

    return str[0] == '-' ? -ans:ans;
}