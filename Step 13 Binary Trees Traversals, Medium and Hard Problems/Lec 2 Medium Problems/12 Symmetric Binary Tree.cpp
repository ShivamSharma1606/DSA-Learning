#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*
 approach 
 if tree is symmetric from a point then it {root left right} and {root right left} will be similar
 */

//tc:  n and sc: n
class Solution {
public:
    bool check(TreeNode* left, TreeNode* right){
        if(left==NULL || right==NULL){
            return left==right;
        }
        if(left->val!=right->val)   return false;

        // going simultaneously left and right and checking theirs child values

        return check(left->right, right->left) && check(right->right, left->left);
    }

    bool isSymmetric(TreeNode* root) {
        return root==NULL || check(root->left,root->right);
    }
};