#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool Recursion(BinaryTreeNode<int>* root){
    if(!root || (!root->left and !root->right))
        return true;
    
    bool left = Recursion(root->left);
    bool right = Recursion(root->right);

    bool ans = true;
    if(root->left){
        ans = ans and (root->left->data <= root->data);
    }

    if(root->right)
        ans = ans and (root->data <= root->right->data);
    
    return ans and left and right;
    

}

bool validateBST(BinaryTreeNode<int> *root) {
    return Recursion(root);
}