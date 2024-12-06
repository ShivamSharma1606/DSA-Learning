/*
Brute force approach : tc: 2n +logn and sc: n
1. dfs traversal store in vector and sort it
2. do inorder traversal and compare the node value to vector value
3. if value is change then correct their value from vector

*/
#include <bits/stdc++.h>
using namespace std;
// optimal approach tc: n and sc: 1

class Solution
{
public:
    TreeNode *first; // we used for edge case II [oneNote bst]
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && root->val < prev->val)
        {

            if (first == NULL)
            { // for case
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }

        prev = root; // Mark this node as prev
        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        // for non-adjacent Node
        if (first && last)
            swap(first->val, last->val);
        // for adjacent Node
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

int main()
{
}