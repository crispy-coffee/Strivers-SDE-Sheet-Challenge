#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void Recursion(BinaryTreeNode<int>* root, int x, int& value){
    if(!root)
        return;
    
    if(x <= root->data and root->data <= value){
        value = root->data;
    }
    Recursion(root->left ,x, value);
    Recursion(root->right,x, value);

}

int findCeil(BinaryTreeNode<int> *node, int x){
    int value = 1000000009;
    Recursion(node, x, value);
    return value==1000000009?-1:value;
}