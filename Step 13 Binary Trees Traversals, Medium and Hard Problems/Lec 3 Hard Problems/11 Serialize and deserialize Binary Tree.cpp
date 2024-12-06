/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
some important link for this question
https://www.geeksforgeeks.org/stringstream-c-applications/
https://www.geeksforgeeks.org/getline-string-c/
*/

// very important question and deserialization especially
class Codec
{
public:
    // tc: o(n) and sc: o(n)

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        queue<TreeNode *> q;
        string s = "";
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == NULL)
            {
                s += "#,";
            }
            else
            {
                s += to_string(node->val) + ",";

                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        stringstream s(data);
        string str;
        // input, storage, delimiting character[at which character we have to read]
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str)); // stoi is used to convert into integers
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            //for the leftchild
            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            //for the right child
            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
