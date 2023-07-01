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

void Recursion(TreeNode<int> *root, vector<int> &left, int level){
    if (root == NULL)
    return;

    if (level == left.size())
    left.push_back(root->data);

    Recursion(root->left, left, level + 1);
    Recursion(root->right, left, level + 1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> left;
    Recursion(root, left, 0);
    return left;
}