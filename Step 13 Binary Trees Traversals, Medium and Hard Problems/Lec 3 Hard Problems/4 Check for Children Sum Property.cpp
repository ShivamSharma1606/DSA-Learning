// dry run is very necessary

#include <bits/stdc++.h>

// gfg solution is o(n^2)
// optimal solution tc: o(n) and sc: o(height)

/*
while going down we increase the node value so that when we come their is no shortage of value
*/
void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
        return;

    int child = 0;

    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child >= root->data)
        root->data = child; // if child sum is greater than root child
    else
    {
        if (root->left)
            root->left->data = root->data; // if left child exist then put value in it
        else if (root->right)
            root->right->data = root->data; // if left child does not exist then put value in it
    }

    changeTree(root->left);
    changeTree(root->right);


    //updating the value of parent after updating the value of childs
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left || root->right)
        root->data = total; // leaf node will not update while we going up[they will only update when we go top to down]
}
