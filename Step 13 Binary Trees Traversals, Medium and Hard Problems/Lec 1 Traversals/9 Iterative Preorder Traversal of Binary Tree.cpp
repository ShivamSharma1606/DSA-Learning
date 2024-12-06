#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/

//tc: o(n) and sc:o(n)

vector<int> preorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int> result;

    if(root==NULL){
        return result;
    }

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        root=st.top();
        st.pop();
        result.push_back(root->val);

        if(root->right!=NULL)   st.push(root->right);
        if(root->left!=NULL)    st.push(root->left);
    }
    return result;
}
int main(){
    
}