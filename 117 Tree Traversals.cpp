#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

void pre(BinaryTreeNode<int> *root,vector<int>& preorder){
    if(!root) return;
    stack<BinaryTreeNode<int> *> st1;
    st1.push(root);
    while(!st1.empty())
    {
        BinaryTreeNode<int> * node=st1.top();
        st1.pop();
        if(node->right) st1.push(node->right);
        if(node->left) st1.push(node->left);
        preorder.push_back(node->data);
    }
    return;
}
void pos(BinaryTreeNode<int> *root,vector<int>& postorder){
    if(!root) return;
    stack<BinaryTreeNode<int> *> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        BinaryTreeNode<int> *node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty()){
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return;
}
void ino(BinaryTreeNode<int> *root,vector<int>& inorder){
    if(!root) return;
    stack<BinaryTreeNode<int> *> st;
    BinaryTreeNode<int> * node=root;
    while(1)
    {
        if(node)
        {
            st.push(node);
            node=node->left;
        }
        else
        {
            if(st.empty()) break;
            node=st.top();
            st.pop();
            inorder.push_back(node->data);
            node=node->right;

        }
    }
    return;
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> preorder,postorder,inorder;
    if(!root) return {inorder,preorder,postorder};
    pre(root,preorder);
    pos(root,postorder);
    ino(root,inorder);
    return {inorder,preorder,postorder};
}