#include <bits/stdc++.h> 
class Queue {
public:
    queue<int> q;

    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return q.empty();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q.push(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(!q.empty()){
            int value = q.front();
            q.pop();
            return value;
        }
        return -1;
    }

    int front() {
        // Implement the front() function
        if(!q.empty()){
            return q.front();
        }
        return -1;
    }
};