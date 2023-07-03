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
pair<int, int> opt_diameter(TreeNode<int>*root){
    if(root==NULL){
        pair<int,int> p= make_pair(0,0);
        return p;
    }
 
    pair<int,int> L = opt_diameter(root->left);
    pair<int,int> R = opt_diameter(root->right);
    int op1 = L.first;
    int op2 = R.first;
    int op3 = L.second + R.second +1;
    int k = max(op1,op2);
    pair<int,int> ans ;
    ans.first= max(op3,k);

    ans.second = max(L.second,R.second)+1;
    return ans;
}


int diameterOfBinaryTree(TreeNode<int> *root)

{
    pair<int,int> finalpair = opt_diameter(root);
    int firstoffinalpair = finalpair.first;
    return firstoffinalpair-1;

}

 
