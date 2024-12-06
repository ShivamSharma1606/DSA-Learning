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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (root->val == key) {
            return helper(root);
        }
        // creating the copy of root
        TreeNode* dummy = root;

        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left) {
            return root->right; // edge case if left sub tree is not present
        } else if (!root->right) {
            return root->left; // edge case if right sub tree is not present
        }

        TreeNode* rightChild = root->right;
        // finding the smallest largest number , of node which has to be deleted
        TreeNode* lastChild = findLastChild(root->left);
        lastChild->right = rightChild;
        return root->left; // return the next left element , of deleted node
    }

    TreeNode* findLastChild(TreeNode* node) {
        if (!node->right) {
            return node;
        }
        return findLastChild(node->right);
    }
};