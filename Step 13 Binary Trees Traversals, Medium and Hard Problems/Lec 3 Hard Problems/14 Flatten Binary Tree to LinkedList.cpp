// brute force approach using recurssion method

class flatternUsingRecursion
{
    // brute force approach using recursion

    void flattern(TreeNode<int> *root, TreeNode<int> *&prev)
    {
        if (root == nullptr)
        {
            return;
        }

        flattern(root->right, prev);
        flattern(root->left, prev);

        root->right = prev;
        root->left = nullptr;

        prev = root;
    }
    void flattenBinaryTree(TreeNode<int> *root)
    {
        // Write your code here.
        TreeNode<int> *prev = nullptr;
        flattern(root, prev);
    }
};

// better approach
class flatternUsingIterative
{
    // better approach
    // using iterative approach using stack
    // tc: o(n) and sc: o(n)
public:
    void flatten(Node *root)
    {
        // code here
        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {

            Node *curr = st.top();
            st.pop();

            if (curr->right)
            {
                st.push(curr->right);
            }

            if (curr->left)
            {
                st.push(curr->left);
            }

            if (!st.empty())
            {
                curr->right = st.top();
            }
            curr->left = nullptr;
        }
    }
};

// optimal approach
// using Morris Traversal

class Solution
{
public:
    // tc: O(n) and sc: o(1)
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *prev = curr->left;
                while (prev->right)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};