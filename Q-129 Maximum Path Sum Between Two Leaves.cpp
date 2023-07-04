#include <bits/stdc++.h> 

long long int maheshdalle(TreeNode<int>* root, long long int &mamta, int &leaf){
    if(!root)
        return 0;
    
    if(!root->left and !root->right)
        leaf++;

    long long int lefty = maheshdalle(root->left, mamta, leaf);
    long long int righty = maheshdalle(root->right, mamta, leaf);

    long long int straight = max((long long int)root->val, max(lefty+root->val, righty+root->val));
    long long int curvy = lefty + righty + root->val;
    mamta = max(mamta, max(straight, curvy));

    return straight;
}

long long int findMaxSumPath(TreeNode<int> *root)
{   
    if(!root)
        return -1;
        
    long long int mamta = root->val;
    int leaf = 0;
    maheshdalle(root, mamta, leaf);
    if(leaf <= 1)
        return -1;
    return mamta;
}