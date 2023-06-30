void PreOrder(TreeNode* root, vector<int>& inr){
    if(root == NULL)
        return;

    inr.push_back(root->data);
    PreOrder(root->left, inr);
    PreOrder(root->right, inr);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> inr;
    PreOrder(root, inr);
    return inr;
}