//brute force approach to traversal and count the number of notes[oneNote]


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
// using the formula node=2^height -1
class Solution {
    // tc: (nlogn)^2 and sc:logn
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh) {
            return (1<<lh) - 1; // 2^lh using bit manipulation
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int leftHeight(TreeNode* node) {
        int height = 0; // intially height is zero
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int rightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};