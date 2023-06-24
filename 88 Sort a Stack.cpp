#include <bits/stdc++.h> 

void sorting(stack<int>& st, int num){

	if(st.empty() || st.top()<num){
		st.push(num);
		return;
	}

	int value = st.top();
	st.pop();
	sorting(st, num);
	st.push(value);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
		return;
		
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	sorting(stack, num);
}