// preorder and inorder 

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
class Solution {
public:
    TreeNode* constructTree(vector<int>& inorder, int inStart, int inEnd, 
                            vector<int>& preorder, int preStart, int preEnd,
                            map<int,int> &mpp){
        
        if(preStart> preEnd || inStart>inEnd){
            return NULL;
        }

        TreeNode* root= new TreeNode(preorder[preStart]);

        int inRoot=mpp[root->val];  // finding the index of root element in inorder vector
        int numsLeft=inRoot-inStart; // finding the number of element at left side from the root 

        root->left=constructTree(inorder, inStart, inRoot-1,preorder, preStart+1,preStart+numsLeft, mpp);
        root->right=constructTree(inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;// it help to time complexit of traversing

        int n=inorder.size();  // same size for preorder

        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root=constructTree(inorder,0,n-1,preorder,0,n-1,mpp);
        return root;
    }
};

//postorder and inorder code can be also same done with some change
// 