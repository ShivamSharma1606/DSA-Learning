#include <bits/stdc++.h>
using namespace std;
// brute force approach : tc: o(2n) and sc: o(n)
class bruteCheckBST
{
    void inorder(BinaryTreeNode<int> *root, vector<int> &result)
    {
        if (root == NULL)
            return;

        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
    bool validateBST(BinaryTreeNode<int> *root)
    {
        // Write your code here

        if (root == NULL)
            return true;
        vector<int> result;
        inorder(root, result);

        for (int i = 1; i < result.size(); i++)
        {
            if (result[i - 1] >= result[i])
            {
                return false;
            }
        }
        return true;
    }
};

// optimal approach
class SolutionOptimal
{
public:
    // tc: O(n) and sc(1)
    bool checking(TreeNode *root, long min, long max)
    {
        if (root == NULL)
            return true;
        if (root->val >= max || root->val <= min)
        {
            return false;
        }
        return checking(root->left, min, root->val) && checking(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root)
    {
        long min = LONG_MIN;
        long max = LONG_MAX;
        return checking(root, min, max);
    }
};