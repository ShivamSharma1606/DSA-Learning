#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
/*
we can use any traversal but we use inorder traversal for our code because other are little complicated
*/
//tc: o(n) and sc: o(height)

// todo: interesting question https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
bool path(TreeNode<int> *root, int x, vector<int> & result){
	if(root==NULL){
		return false;
	}
	result.push_back(root->data);

	if(root->data==x)	return true;

	if(path(root->left,x,result)||path(root->right,x,result))	return true;

	result.pop_back();
	return false;	
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> result;
	if(!root)	return result;
	path(root,x,result);
	return result;
}
