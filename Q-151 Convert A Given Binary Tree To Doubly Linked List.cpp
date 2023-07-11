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

void solve(BinaryTreeNode<int>* root, vector<int>& inorder){
    if(!root) return;
    solve(root->left, inorder);
    inorder.push_back(root->data);
    solve(root->right, inorder);
}

BinaryTreeNode<int>* usingstorage(BinaryTreeNode<int>* root){
    vector<int> inorder;
    solve(root, inorder);
    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* tail =head;
    tail->left = NULL;
    for(auto i:inorder){
        tail->right = new BinaryTreeNode<int>(i);
        tail->right->left = tail;
        tail = tail->right;
    }
    tail->right = NULL;
    return head->right;
}



void withoutspace(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &tail){
    if(!root)
        return;
    
    withoutspace(root->left, tail);
    tail->right = new BinaryTreeNode<int>(root->data);
    tail->right->left = tail;
    tail = tail->right;
    withoutspace(root->right, tail);


}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // 1 Using space
    // usingstorage(root);

    // 2 Without using space;
    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* tail = head;
    withoutspace(root, tail);
    return head->right;

}