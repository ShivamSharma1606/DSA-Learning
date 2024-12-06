// also do with inorder traversal , i have done with level order traversal
// tc: o(nlog) and sc: o(n)
// oneNote dry run is necessary and make all datastructure properly
/* https://chatgpt.com/c/672dbd0b-a74c-8004-baac-76fe59cac8c4 more help*/
// doubt about map and insert is clear in that https://chatgpt.com/c/673c745a-5d98-8004-9eba-3c6520584cb0

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

// optimal solution Time Complexity: O(N * log2N * log2N * log2N) and Space Complexity: O(N + N/2)
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // value location map 1. for vertical index, map 2. multiset 1. for level index 2. for value[can be multiple same]
        map<int, map<int, multiset<int>>> vl; // value location
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // vertical index of root: 0 and level index of root: 0

        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first; // getting the node
            int x = p.second.first;   // getting vertical value
            int y = p.second.second;  // getting horizontal value

            vl[x][y].insert(node->val); // pushing the node 1.value 2.vertical level 3.horizontal level

            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}}); // as we go ,left vertical level always decrease and horizontal level alway increase as we go down
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}}); // as we go, right vertical level always increase and horizontal level alway increase as we go down
            }
        }

        vector<vector<int>> result;
        for (auto p : vl)
        {
            vector<int> temp; // temporary store horizontal value of the graph
            for (auto q : p.second)
            {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            result.push_back(temp);
        }
        return result;
    }
};

// same code but using vector more time complexity because using vector instead of multiset and have to sort that at end of the result
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
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto f = q.front();
                q.pop();
                TreeNode *node = f.first;
                auto pos = f.second;
                int xpos = pos.first;
                int ypos = pos.second;
                if (node->left)
                    q.push({node->left, {xpos - 1, ypos + 1}});
                if (node->right)
                    q.push({node->right, {xpos + 1, ypos + 1}});
                mp[xpos].push_back({node->val, ypos});
            }
        }

        vector<vector<int>> ans;
        for (auto i : mp)
        {
            sort(i.second.begin(), i.second.end(), [&](auto p1, auto p2)
                 {
                if(p1.second == p2.second) {
                    return p1.first < p2.first;
                }
                return p1.second < p2.second; });
            vector<int> temp;
            for (auto j : i.second)
            {
                temp.push_back(j.first);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
