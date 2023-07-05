#include <bits/stdc++.h> 
/*
TreeNode<int>* solve(int index, int start, int end, vector<int>& inorder, vector<int>& preorder, unordered_map<int,int>& location){
    
    if(index == preorder.size())
        return NULL;

    if(start>end)
        return NULL;

    int element = preorder[index];
    TreeNode<int>* root = new TreeNode<int>(element);
    root->left = solve(index+1, start, location[element]-1, inorder, preorder, location);
    root->right = solve(index+1, location[element]+1, end, inorder, preorder, location);

    return root;

}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int,int> location;
    for(int i=0; i<inorder.size(); i++){
        location[inorder[i]] = i;
    }

    return solve(0, 0, inorder.size()-1, inorder, preorder, location);

}
*/


#include <unordered_map>

TreeNode<int> *rec(vector<int> &inorder,int iL,int iH, vector<int> &preorder,int pL,int pH,unordered_map<int,int>&mp)

{

    if(iL>iH || pL>pH)

    return NULL;

    TreeNode<int> * root=new TreeNode<int>(preorder[pL]);

    int currInd=mp[root->data];

    int inorderLInd=currInd-iL;

    root->left=rec(inorder,iL,currInd-1,preorder,pL+1,pL+inorderLInd,mp);

    root->right=rec(inorder,currInd+1,iH,preorder,pL+inorderLInd+1,pH,mp);

    return root;

}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)

{

    //    Write your code here

    unordered_map<int,int>mp;

    int n=inorder.size();

    for(int i=0;i<n;i++)

    mp[inorder[i]]=i;

    return rec(inorder,0,n-1,preorder,0,n-1,mp);

}



