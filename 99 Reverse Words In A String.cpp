    #include<stack>
string reverseString(string &str){
	// Write your code here.	
	stack<string> s;
	int start = -1;
	for(int end=0; end<str.size(); end++){
		while(str[end] == ' '){
			end++;
		}
		if(end == str.size()) break;
		start = end;
		while(end<str.size() and str[end] != ' '){
			end++;
		}
		s.push(str.substr(start, end-start));
	}
	str = "";

	while(!s.empty()){
		str += s.top(); 
		s.pop();
		if(!s.empty());
			str += ' ';
	}	
	return str;
}