#include <bits/stdc++.h> 

void leftybc(TreeNode<int>* root, vector<int>& ans){
    if(!root or (!root->left and !root->right)){
        return;
    }

    ans.push_back(root->data);

    if(root->left)
        leftybc(root->left, ans);
    else
        leftybc(root->right, ans);

}

void choticaste(TreeNode<int>* root, vector<int>& ans){
    if(!root)
        return;
    
    if(!root->left and !root->right){
        ans.push_back(root->data);
        return;
    }

    choticaste(root->left, ans);
    choticaste(root->right, ans);

}

void rightybc(TreeNode<int>* root, vector<int>& ans){
    if(!root or (!root->left and !root->right))
        return;
    

    if(root->right)
        rightybc(root->right, ans);
    else    
        rightybc(root->left, ans);
        
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    if(!root)
        return {};

    vector<int> ans;

    //root bhadwa ho gya
    ans.push_back(root->data);

    //traverse left first
    leftybc(root->left, ans);

    //choti case ke log
    choticaste(root->left, ans);
    choticaste(root->right, ans);

    //traverse right then
    rightybc(root->right, ans);

    return ans;

}