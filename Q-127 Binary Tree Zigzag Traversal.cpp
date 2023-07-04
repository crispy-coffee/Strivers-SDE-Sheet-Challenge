#include <bits/stdc++.h> 

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(!root)
        return {};
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool reverse = true;
    vector<int> ans;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        while(size--){
            auto front = q.front();
            q.pop();
            temp.push_back(front->data);
            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }
        if(reverse){
            for(auto i:temp){
                ans.push_back(i);
            }
            reverse = !reverse;
        }else{
            for(int i=temp.size()-1; i>=0; i--){
                ans.push_back(temp[i]);
            }
            reverse = !reverse;
        }
    }
    return ans;
}
