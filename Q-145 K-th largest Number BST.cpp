#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int K;
void Recursion(TreeNode<int>* root, int& count, int& value){
    if(!root)
        return;
    
    Recursion(root->right, count, value);
    count++;
    if(count==K)
        value = root->data;

    Recursion(root->left, count, value);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{   
    int value = -1;
    K=k;
    int count = 0;
    Recursion(root,count , value);
    return value;
    
}
