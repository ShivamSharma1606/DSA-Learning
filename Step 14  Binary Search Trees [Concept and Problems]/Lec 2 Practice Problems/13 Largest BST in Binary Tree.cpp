// largest bst
// dry run must
/*
?STATUS[DONE]
todo:  https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
*/

/*
*Brute force approach    tc: o(n^2) and sc: o(n)
    1. first create an function to validate for bst
    2. create and fuction to find the height of bst
    3. while we traversing we check fore each node [it is bst or not using our function]
    4. if it bst then find the height using function
    5. Compare with our previous height and update according to it
    6. return the max height at last
*/

//*optimal approach[oneNote]     tc:n and sc: 1
/*
    1. find the largest of left of that node (let ll)
    2. find the smallest of right of that node (let rs)
    3. if   ll<node<rs satisfy then it is size=ls.size+rs.size+1
    4. return the max size
    It can be done with postorder
*/

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
// creating a class
class NodeValue
{
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

NodeValue findinglargest(TreeNode *root)
{

    // leaf node or empty bst
    if (!root)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    auto left = findinglargest(root->left);
    auto right = findinglargest(root->right);

    if (root->data > left.maxNode && root->data < right.minNode)
    { // It is a BST
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    // above condition is not satisfy so return that values that are not comparable with other subtree
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode *root)
{
    // Write your code here.
    return findinglargest(root).maxSize;
}

class todoQuestion
{
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
    class NodeValues
    {
    public:
        int min, max, size, sum;
        NodeValues(int min, int max, int size, int sum)
        {
            this->min = min;
            this->max = max;
            this->size = size;
            this->sum = sum;
        }
    };

    class Solution
    {
    public:
        NodeValues finder(TreeNode *root, int &result)
        {
            if (!root)
            {
                return NodeValues(INT_MAX, INT_MIN, 0, 0);
            }

            auto left = finder(root->left, result);
            auto right = finder(root->right, result);

            // checking bst
            if (root->val > left.max && root->val < right.min)
            {
                int current_sum = root->val + left.sum + right.sum;
                result = max(result, current_sum);
                return NodeValues(min(root->val, left.min), max(root->val, right.max), left.size + right.size + 1, current_sum);
            }
            // if don't satisfy the condition of BST
            return NodeValues(INT_MIN, INT_MAX, max(left.size, right.size), 0);
        }
        int maxSumBST(TreeNode *root)
        {
            int result = 0;
            finder(root, result);
            return result;
        }
    };
};

