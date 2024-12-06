/*
https://takeuforward.org/data-structure/binary-search-tree-iterator
https://leetcode.com/problems/binary-search-tree-iterator/
*/

/*
*brute force apprach using inorder vector
sc: o(n) and tc: o(n)
*/

//*better approach sc: o(height) and tc: o(1)

/*
if want to find before than we have to do our execution like that: right center left[reverse inorder]
change the logic pushAll(temp->right);  to pushAll(temp->left); and
change the logic root=root->left; to root=root->right;
*/
class BSTIterator
{
public:
    stack<TreeNode *> st;

    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAll(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};
