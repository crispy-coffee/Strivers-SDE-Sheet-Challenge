int Recursion(vector<int>& values, vector<int>& weights, int index, int w){
	if(index == values.size())
		return 0;

	int include = 0,exclude=0;

	if(w-weights[index]>=0){
		include = values[index] + Recursion(values, weights, index+1, w-weights[index]);
	}
	exclude = Recursion(values, weights, index+1, w);

	return max(include, exclude);
}

int Memoization(vector<int>& values, vector<int>& weights, int index, int w, vector<vector<int>>& dp){
	if(index == values.size())
		return 0;

	// if(w<=0)
		// return 0;
	
	if(dp[index][w] != -1)
		return dp[index][w];

	int include=0, exclude=0;

	if(w-weights[index]>=0){
		include = values[index] + Memoization(values, weights, index+1, w-weights[index], dp);
	}
	exclude = Memoization(values, weights, index+1, w, dp);

	return dp[index][w] = max(include, exclude);
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{	
	// 1 Recursion
	// return Recursion(values, weights, 0, w);

	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return Memoization(values, weights, 0, w, dp);
}