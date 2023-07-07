#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    
    if(!root)
        return;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        BinaryTreeNode<int>* first = NULL;
        while(size--){
            auto top = q.front();
            q.pop();
            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
            
            if(first == NULL){
                first = top;
            }else{
                first->next = top;
                first = top;
            }
        }
        first->next = NULL;
    }
    return;
}




