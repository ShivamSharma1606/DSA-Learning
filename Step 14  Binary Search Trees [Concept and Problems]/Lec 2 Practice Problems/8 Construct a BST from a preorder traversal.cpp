/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// tc: n and sc: 1
class Solution
{
public:
    TreeNode *result(vector<int> &preorder, int &i, int bound)
    {
        // second condition is necessary for node->left for inserting element in left subtree and don't insert the larger element by chance
        if (i == preorder.size() || preorder[i] > bound)
            return nullptr;

        // creating the node
        TreeNode *node = new TreeNode(preorder[i++]);

        // reduce the size[view] of array using upper bound
        node->left = result(preorder, i, node->val);
        // we don't need lower bound because we have already insert the left subtree and checking the condition in above if()
        // our i value is already increased so their is no scope to insert lower element at right
        node->right = result(preorder, i, bound);
        return node;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int bound = INT_MAX;
        int i = 0;
        return result(preorder, i, bound);
    }
};