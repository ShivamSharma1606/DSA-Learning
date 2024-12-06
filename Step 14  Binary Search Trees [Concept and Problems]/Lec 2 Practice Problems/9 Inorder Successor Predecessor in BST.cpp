// todo: [status->done] also do the same question for predecessor[https://www.naukri.com/code360/problems/predecessor-and-successor-in-bst_893049]
// todo: [statud->done] also do the both same question for binary tree[https://www.naukri.com/code360/problems/inorder-sucessor_799913]

// **brute force approach : tc o(n) and sc: o(n)
/*
1 first create the vector which have inorder elemnt
2 return the element next to the given elemnt [that will be is successor]
*/

// *better approach : tc o(n) and sc: o(1)
/*
1 do any inorder traversal and return the first value which is greater than 8
*/

// *optimal approach: tc o(height) and sc: o(1)

class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *,(Node *root, Node *x)
    {
        // Your code here
        Node *successor = NULL;
        while (root)
        {
            if (x->data >= root->data)
            {
                root = root->right;
            }
            else
            {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};
