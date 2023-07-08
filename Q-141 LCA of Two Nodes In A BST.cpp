#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	 if(!root)
            return NULL;
        
    if(root->data > p->data and root->data > q->data){
        root = LCAinaBST(root->left, p, q);
    }

    if(root->data < p->data and root->data < q->data){
        root = LCAinaBST(root->right, p, q);
    }
    
    return root;

}
