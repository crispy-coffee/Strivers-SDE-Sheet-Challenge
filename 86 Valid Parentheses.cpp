
bool isValidParenthesis(string str) {
  // Write your code here.
    stack<char> s;

    for(auto ch:str){

        if(ch == ')' and !s.empty() and s.top() == '('){
            s.pop();
        }else if(ch == ']' and !s.empty() and s.top() == '['){
            s.pop();
        }else if(ch == '}' and !s.empty() and s.top() == '{'){
            s.pop();
        }else{
            s.push(ch);
        }
        
    }

    return s.empty();

}