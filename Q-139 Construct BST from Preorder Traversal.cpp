#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* Recursion(vector<int>& nums,int low,int high)
{
    if(low>high)
        return NULL;

    int mid= low+(high-low)/2;
    TreeNode<int>* root = new TreeNode<int>(nums[mid]);
    root->left=Recursion(nums,low,mid-1);
    root->right=Recursion(nums,mid+1,high);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    sort(preOrder.begin(), preOrder.end());
    return Recursion(preOrder,0,preOrder.size()-1);
}