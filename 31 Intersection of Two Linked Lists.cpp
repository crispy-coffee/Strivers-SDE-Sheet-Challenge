#include<bits/stdc++.h>
Node* findIntersection(Node *first, Node *second)
{
    //Write your code here
    unordered_map<Node*,bool> visited;

    while(first){
        visited[first] = true;
        first = first->next;
    }

    while(second){
        if(visited.find(second) != visited.end())
            return second;
        second = second->next;
    }
    if(visited.find(second) != visited.end())
        return second;
    return NULL;
}