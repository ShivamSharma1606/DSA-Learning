#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
//tc: n and sc: n
/*
approach is that which is the first element of any level will be seen from the top
*/
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> result;
    queue<pair<TreeNode<int>*, int>> q; // Node, horizontal level
    map<int,int> mpp;
    q.push({root,0});

    while(!q.empty()){
        auto tn=q.front();
        q.pop();
        TreeNode<int> *node=tn.first;
        int hlevel=tn.second;

        if(mpp.find(hlevel)==mpp.end()){
            mpp[hlevel]=node->data;
        }

        if(node->left)  q.push({node->left,hlevel-1});
        if(node->right) q.push({node->right,hlevel+1});
    }

    for(auto it:mpp){
        result.push_back(it.second);
    }
    return result;
}
