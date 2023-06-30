void PostOrder(TreeNode* root, vector<int>& inr){
    if(root == NULL)
        return;

    PostOrder(root->left, inr);
    PostOrder(root->right, inr);
    inr.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> inr;
    PostOrder(root, inr);
    return inr;
}