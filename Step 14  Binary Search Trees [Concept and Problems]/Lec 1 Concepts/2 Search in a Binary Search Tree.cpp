// brute force approach
bool searchInBST(BinaryTreeNode<int> *root, int x)
{

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();

            if (node->data == x)
                return true;

            if (node->data > x)
            {
                if (node->left)
                {
                    q.push(node->left);
                }
            }
            else
            {
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
    }
    return false;
}

// optimal approach

class Solution
{
public:
    // tc: log(base2)N
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL && root->val != val)
        {
            if (val > root->val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};