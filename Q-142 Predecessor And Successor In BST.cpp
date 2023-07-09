#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void Recursion(BinaryTreeNode<int>* root, int key, vector<int>& ans){

    if(!root)
        return;
    
    Recursion(root->left, key, ans);
    ans.push_back(root->data);
    Recursion(root->right, key, ans);

}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{   
    vector<int> ans;
    Recursion(root, key, ans);
    pair<int,int> result = {-1,-1};

    for(int i=0; i<ans.size(); i++){
        if(ans[i] == key){
            if(i==0 and i!=ans.size()-1){   
                result.second = ans[i+1];
            }else if(i==ans.size()-1 and i!=0){
                result.first = ans[i-1];
            }else if(0<i and i<ans.size()-1){
                result = {ans[i-1], ans[i+1]};
            }
            break;
        }
    }
    return result;
}
