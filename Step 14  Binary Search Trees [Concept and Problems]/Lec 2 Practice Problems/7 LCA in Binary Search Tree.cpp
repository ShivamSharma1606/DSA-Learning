//brute force approach using apply same algo of binary tree

//optimal approach using while loop[I prefered this more]
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small=min(p->val,q->val);
        int large=max(p->val,q->val);

        while(root){
            if(root->val > large){  // both the value are lesser than root
                root=root->left;
            }
            else if(root->val <small){ //both the value are greater than root
                root=root->right;
            }
            else{  //mean path is spliting
                return root;
            }
        }
        return nullptr;
    }
};


//optimal approah using recursion technique [both optimal are same]
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==nullptr)   return nullptr;

    int curr=root->data;
    if(curr< P->data && curr<Q->data){  //both the value are greater than root value
        return LCAinaBST(root->right, P, Q);
    }
    if(curr> P->data && curr>Q->data){  //both the value are lessert than root value
        return LCAinaBST(root->left, P, Q);
    }

    return root; //hence both above condition are not satisfy that mean that is root
}