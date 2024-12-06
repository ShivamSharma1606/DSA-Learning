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
// brute force approach
// using recusion tc:n*n and sc: n
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);

        if (abs(lefth - righth) > 1)
            return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right)
            return false;
        return true;
    }
};

int main()
{
}

// optimal approach tc: o(n) and sc: o(n)
// covert height of bt into this code
// using postorder traversal

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int maxDepth(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    if (lh == -1 || rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalancedBT(TreeNode<int> *root)
{
    // Write your code here.
    return maxDepth(root) != -1;
}