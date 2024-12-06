#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * node, int X)
{
    // Write your code here.
    int floor=-1;
    while(node){
        if(node->val==X){
            return X;
        }

        if (X > node->val) {
            floor = node->val;
            node = node->right;
        } else {
            node=node->left;
        }
    }
    return floor;
}