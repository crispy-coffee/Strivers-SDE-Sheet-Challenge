#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void solve(BinaryTreeNode<int>* root, vector<int>& inorder){
    if(!root)
        return;
    solve(root->left ,inorder);
    inorder.push_back(root->data);
    solve(root->right, inorder);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> inorder;
    solve(root, inorder);
    int start = 0, end = inorder.size()-1;
    while(start<end){
        if(inorder[start]+inorder[end] == k){
            return true;
        }else if(inorder[start]+inorder[end] < k){
            start++;
        }else{
            end--;
        }
    }
    
    return false;
}