#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> s,t;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!s.empty()){
            int value = s.top();
            s.pop();
            t.push(value);
        }

        t.push(val);

        while(!t.empty()){
            int value = t.top();
            t.pop();
            s.push(value);
        }

    }

    int deQueue() {
        // Implement the dequeue() function.
        if(!s.empty()){
            int value = s.top();
            s.pop();
            return value;
        }
        return -1;
    }

    int peek() {
        // Implement the peek() function here.
        if(!s.empty()){
            return s.top();
        }
        return -1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s.empty();
    }
};