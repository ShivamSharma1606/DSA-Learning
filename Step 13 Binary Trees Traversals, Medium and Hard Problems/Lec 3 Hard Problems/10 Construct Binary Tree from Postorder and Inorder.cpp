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
// tc : o(n) and sc: o(n)
// we are using map because find value is faster in it [if use vector for each
// element time complexity will be o(n) and lead to total O(n^2)]

class Solution {
public:
    TreeNode* constructTree(vector<int>& inorder, int inStart, int inEnd,
                            vector<int>& postorder, int preStart, int preEnd,
                            map<int, int>& mpp) {

        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[preEnd]);

        int inRoot = mpp[root->val]; // finding the index of root element in
                                     // inorder vector
        int numsLeft = inRoot - inStart; // finding the number of element at left side from the root

        root->left = constructTree(inorder, inStart, inRoot - 1, postorder,
                                   preStart, preStart + numsLeft - 1, mpp);
        root->right = constructTree(inorder, inRoot + 1, inEnd, postorder,
                                    preStart + numsLeft, preEnd - 1, mpp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp; // it help to time complexit of traversing

        int n = inorder.size(); // same size for postorder

        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root =
            constructTree(inorder, 0, n - 1, postorder, 0, n - 1, mpp);
        return root;
    }
};