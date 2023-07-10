#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int K;

void inorder(TreeNode<int>* root, int& count, int& ans){
    if(!root)
        return;
    inorder(root->left, count, ans);
    count++;
    if(count == K) 
        ans = root->data;
    
    inorder(root->right, count, ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{   
    K=k;
    int count = 0;
    int ans = -1;
    inorder(root , count, ans);
    return ans;
}