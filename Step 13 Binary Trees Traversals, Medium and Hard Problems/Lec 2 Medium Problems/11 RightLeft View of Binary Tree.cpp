#include<bits/stdc++.h>
using namespace std;
// try to do code with approach first
// tc: o(n) and sc:o(height)

// right side view

/*
*approach 1 (in this case it will take little more space) Iterative approach
1. we do level order traversal from left to right but if we do from right to left
2. then first node of each level will be the right side view

*approach 2
1. we know predorder traversal is  node left right
2. but we do reverse preordertraversal i.e node right left
3. the first element of reverse_preordertraversal will be our right side view
*/
class Solution
{
public:
    vector<int> result;
    void rightView(TreeNode *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (result.size() == level)
        { // very smart move
            result.push_back(root->val);
        }
        //little bit tricky
        rightView(root->right, level + 1);
        rightView(root->left, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {

        rightView(root, 0);
        return result;
    }
};

// left side view

#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void leftView(TreeNode<int> *root, int level, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    if (result.size() == level)
    { // very smart move
        result.push_back(root->data);
    }
    leftView(root->left, level + 1, result);
    leftView(root->right, level + 1, result);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> result;
    leftView(root, 0, result);
    return result;
}