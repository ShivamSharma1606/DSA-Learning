#include<bits/stdc++.h>
using namespace std;
// if both tree are same then their any traversal will be same
//!  tc: o(n)


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //it preorder traversal we can do with any traversal
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return(p==q);
        }

        return (p->val==q->val)
            && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
    }
};