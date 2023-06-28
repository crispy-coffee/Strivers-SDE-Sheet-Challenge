int zAlgorithm(string text, string pattern, int nn, int mm)
{
	int n = text.size()-pattern.size()+1;
	int m = pattern.size();
	int ans = 0;
	for(int i=0; i<n; i++){
		string temp = text.substr(i, m);
		if(temp == pattern){
			ans++;
		}
	}

	return ans;
}