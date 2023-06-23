#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q,p;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        p.push(element);
        while(!q.empty()){
            int value = q.front();
            q.pop();
            p.push(value);
        }

        while(!p.empty()){
            int value = p.front();
            p.pop();
            q.push(value);
        }

    }

    int pop() {
        // Implement the pop() function.
        if(!q.empty()){
            int value = q.front();
            q.pop();
            return value;
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }
};