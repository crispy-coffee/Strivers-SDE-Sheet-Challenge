#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
/*
void Recursion(BinaryTreeNode<int> * root, map<int,vector<int>>& view, int line){
    if(!root)
        return;
    
    view[line].push_back(root->data);
    Recursion(root->left, view, line-1);
    Recursion(root->right, view, line+1);
    
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    map<int,vector<int>> view;
    Recursion(root, view, 0);

    vector<int> result;
    for(auto &child:view){
        result.push_back(child.second.back());
    }

    return result;
}
*/
vector<int> bottomView(BinaryTreeNode<int> * root){
    // Approach: Similar to Vertical Order Traversal of Binary Tree.
    // We will use a one to one mapping of the horizontal distance
    // and the last occurence of the value at that distance on the 
    // number line. As all the remaining nodes will be hidden.
    // Time Complexity: O(N*logN)
    // Space Complexity: O(N)
    map<int, int> hash;
    vector<int> ans;
    if(root == NULL) return ans;
    // We will do a Level Order Traversal
    queue<pair<BinaryTreeNode<int>*, int>> q;
    pair<BinaryTreeNode<int>*, int> p = make_pair(root, 0);
    q.push(p);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            pair<BinaryTreeNode<int>*, int> curr = q.front();
            q.pop();
            hash[curr.second] = curr.first->data;
            if(curr.first->left != NULL){
                pair<BinaryTreeNode<int>*, int> p = make_pair(curr.first->left, curr.second - 1);
                q.push(p);
            }
            if(curr.first->right != NULL){
                pair<BinaryTreeNode<int>*, int> p = make_pair(curr.first->right, curr.second + 1);
                q.push(p);
            }
        }
    }

    for(auto it : hash){
        ans.push_back(it.second);
    }

    return ans;
    
}
