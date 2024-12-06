/*
brute force approach    
tc: 2(n) and sc: 2(n)

1. first find the path from root to both of the node and store in vector(or any other data structure)
2. after finding path of both node use single pointer on both array and compare their value and store some where if they are same let(ancestor)
3. traverse through array using pointer if both the value in vector are same update the ancestor
4. if value are different then return the last ancestor that is store
*/

//optimal approach

// very intersting dry run in one note task section


//optimal approach
//tc: n and sc:n
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){  
            return root;
        }

        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        if(left==NULL){  //our left branch has nothing then our element may be in right
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }
    }
};