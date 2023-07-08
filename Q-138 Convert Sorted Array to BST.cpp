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
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return Recursion(arr,0,n-1);
}