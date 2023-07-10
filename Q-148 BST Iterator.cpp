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

class BSTiterator
{   
    public:
    vector<int> inorder;
    int start;
    void recursion(TreeNode<int>* root){
        if(!root)
            return;
        recursion(root->left);
        inorder.push_back(root->data);
        recursion(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {   
        recursion(root);
        start = 0;
    }

    int next()
    {
        return inorder[start++];
    }

    bool hasNext()
    {
        if(start<inorder.size())
            return true;
        return false;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/