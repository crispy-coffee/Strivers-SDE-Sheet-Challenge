#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
/*
pair<bool, int> recursion(TreeNode<int>* root){
    if(!root)
        return {true, 0};
    
    if(!root->left and !root->right)
        return {true, 1};

    pair<bool,int> left = recursion(root->left);
    pair<bool,int> right = recursion(root->right);

    if(root->left and root->right and root->left->data <= root->data and root->data <= root->right->data and left.first and right.first ){
        root->data = max({root->data, root->left->data, root->right->data});
        return {true, left.second + right.second+1};
    }else if(root->left and !root->right and root->left->data <= root->data and left.first){
        root->data = max(root->data, root->left);
        return {true, left.second+1};
    }else if(!root->left and root->right and root->data <= root->right->data and right.first){
        
        return {true, right.second+1};
    }else{
        return {false, max(left.second, right.second)};
    }

}

int largestBST(TreeNode<int>* root) 
{
    return recursion(root).second;
}
*/
class Info{
    public:
        int maxi;
        int mini;
        bool isValid;
        int size;
    public:
        Info(){
            maxi = INT_MIN;
            mini = INT_MAX;
            isValid = true;
            size = 0;
        }
};



Info* solver(TreeNode<int>* root, int &ans){
    if(root == NULL){
        Info* node = new Info;
        return node;
    }

    Info* left = solver(root->left, ans);
    Info* right = solver(root->right, ans);

    Info *head = new Info;
    head->maxi = max(right->maxi, root->data);
    head->mini = min(left->mini, root->data);
    head->size = left->size + right->size + 1;

    if(left->isValid && right->isValid && (root->data > left->maxi && root->data < right->mini)){
        head->isValid = true;
    }
    else{
        head->isValid = false;
    }

    if(head->isValid) ans = max(ans, head->size);

    return head;
}


int largestBST(TreeNode<int>* root) 
{

    int maxAns = 0;
    Info* result = solver(root, maxAns);

    return maxAns;
}


