#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 /*BruteForce
	vector<int> inc(n),out(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j) continue;
			if(knows(i, j)){
				out[i]++;
				inc[j]++;
			}
		}
	}

	for(int i=0; i<n; i++){
		if(out[i] == 0 and inc[i] == n-1){
			return i;
		}
	}

	return -1;
	*/
	stack<int>st;
     for(int i=0;i<n;i++) st.push(i);
     while(st.size()>1)
     {
         int i=st.top();
         st.pop();
         int j=st.top();
         st.pop();
         if(knows(i,j)) st.push(j);
         else st.push(i);
     }
     int ans=st.top();
     st.pop();
     for(int i=0;i<n;i++)
     {
         if(i!=ans)
         {
             if((knows(i,ans)==false || knows(ans,i)==true)) return -1;
         }
     }
     return ans;

}