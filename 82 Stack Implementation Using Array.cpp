#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    stack<int> s;
    int size;
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(s.size()<size){
            s.push(num);
        }
    }

    int pop() {
        // Write your code here.
        if(!s.empty()){
            int value = s.top();
            s.pop();
            return value;
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(!s.empty())
            return s.top();
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return s.empty();
    }
    
    int isFull() {
        // Write your code here.
        return s.size()==size;
    }
    
};