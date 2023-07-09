#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void Recursion(TreeNode<int>* root, int x, int& value){
    if(!root)
        return;
    
    if(value <= root->val and root->val <= x){
        value = root->val;
    }
    Recursion(root->left ,x, value);
    Recursion(root->right,x, value);

}


int floorInBST(TreeNode<int> * root, int X)
{   
    int value = 0;
    Recursion(root, X, value);
    return value;
}