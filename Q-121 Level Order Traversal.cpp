#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root) 
       return {};
    queue<BinaryTreeNode<int>*>q;
    vector<int> ans;;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        while (s--) {
          auto it = q.front();
          ans.push_back(it->val);
          q.pop();
          if (it->left)
            q.push(it->left);
          if (it->right)
            q.push(it->right);
        }
    }
    return ans;
}