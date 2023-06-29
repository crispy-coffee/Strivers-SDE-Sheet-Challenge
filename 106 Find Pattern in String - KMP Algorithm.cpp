#include <bits/stdc++.h> 
bool findPattern(string pattern, string text)
{
    int n = text.size()-pattern.size()+1;
	int m = pattern.size();
	int ans = 0;
	for(int i=0; i<n; i++){
		string temp = text.substr(i, m);
		if(temp == pattern){
			return true;;
		}
	}

	return false;
}