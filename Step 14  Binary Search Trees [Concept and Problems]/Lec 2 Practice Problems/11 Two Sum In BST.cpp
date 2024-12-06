/*
brute force apprach : tc: 2n and sc: n
1. create inorder vector
2. apply 2 sum algorithm on it
*/

// optimal approach: tc: n and sc: height*2

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
class BSTIterator
{
public:
    stack<TreeNode *> st;
    // reverse.true= befor[decending order]
    // reverse.false=next[acending order]
    bool reverse = true;

    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if (!reverse)
            pushAll(temp->right); // pushing order L N R [acending order]
        else
            pushAll(temp->left); // pushing order R N L [decending order]

        return temp->val;
    }

    bool hasNext() { return !st.empty(); }

    void pushAll(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            if (!reverse)
            {
                root = root->left; // Left Only
            }
            else
            {
                root = root->right; // Right Only
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        BSTIterator l(root, false); // finding element from the acending order
        BSTIterator r(root, true);  // finding element from the decending order

        int i = l.next();
        int j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next(); // get the next element from ascending order
            else
                j = r.next(); // r.prev()   // get the next element from decresing order
        }
        return false;
    }
};
