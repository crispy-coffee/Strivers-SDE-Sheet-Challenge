#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
void Recursion(TreeNode<int>* root, vector<int>& ans, int x){
	if(!root)
		return;
		
	ans.push_back(root->data);

	if(root->data == x)
		return;
	
	Recursion(root->left, ans, x);
	Recursion(root->right, ans, x);

	if(ans.back() != x)
		ans.pop_back();

}

vector<int> pathInATree(TreeNode<int> *root, int x)
{	
	vector<int> ans;
	Recursion(root, ans,x);
	return ans;
}
