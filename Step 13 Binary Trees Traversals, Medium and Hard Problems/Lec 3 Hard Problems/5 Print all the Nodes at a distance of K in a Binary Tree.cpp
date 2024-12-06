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
1. first find the parent of each node
2. then move radially[up left right]
3. move radially till distance k
4. the element get distance k will be our result
*/

// tc: o(2*n) + logn and sc: o(n)
class Solution
{
public:
    void parentvisit(TreeNode *root,unordered_map<TreeNode *, TreeNode *> &parent_track)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *cp = q.front(); // cp: current parent
            q.pop();
            if (cp->left)
            {
                q.push(cp->left);
                parent_track[cp->left] = cp;
            }
            if (cp->right)
            {
                q.push(cp->right);
                parent_track[cp->right] = cp;
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        parentvisit(root, parent_track);

        int pc = 0; // path covered till date
        unordered_map<TreeNode *, bool> visited;
        visited[target] = true;

        queue<TreeNode *> q;
        q.push(target);

        while (!q.empty())
        {
            int n = q.size();
            if (pc++ == k)
                break;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left && !visited[node->left])
                {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if (node->right && !visited[node->right])
                {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if (parent_track[node] && !visited[parent_track[node]])
                {
                    visited[parent_track[node]] = true;
                    q.push(parent_track[node]);
                }
            }
        }

        vector<int> result;
        while (!q.empty())
        {
            TreeNode *sol = q.front();
            q.pop();
            result.push_back(sol->val);
        }

        return result;
    }
};