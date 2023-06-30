void inorder(TreeNode* root, vector<int>& inr){
    if(root == NULL)
        return;

    inorder(root->left, inr);
    inr.push_back(root->data);
    inorder(root->right, inr);
}

vector<int> getInOrderTraversal(TreeNode *root)
{   
    vector<int> inr;
    inorder(root, inr);
    return inr;

}