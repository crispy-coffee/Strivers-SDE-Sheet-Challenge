#include <bits/stdc++.h> 

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {

    if(!root1 and !root2)
        return true;
    
    if(!root1 or !root2)
        return false;
    
    bool left = identicalTrees(root1->left, root2->left);
    bool centre = root1->data == root2->data;
    bool right = identicalTrees(root1->right, root2->right);

    if(centre and left and right)
        return true;
    
    return false;

}