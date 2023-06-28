vector<int> stringMatch(string text, string pattern) {

	int n = text.size()-pattern.size()+1;
	int m = pattern.size();
	vector<int> ans;
	for(int i=0; i<n; i++){
		string temp = text.substr(i, m);
		if(temp == pattern){
			ans.push_back(i+1);
		}
	}

	return ans;
}
