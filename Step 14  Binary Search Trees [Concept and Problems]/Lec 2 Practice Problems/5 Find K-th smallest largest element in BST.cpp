// brute force approach
//tc: o(n) and sc: o(n)
/*
1 use any bfs technique (pre in post-order)
2 ans store the value of node in container(like vector)
3 sort the array
4 return the value for that paticular index
*/

//optimal approach

// we use counter & inorder [it has the property that it alway store node in sorted order]

//leetcode for ksmallest


class Solution {
public:
    void inorder(TreeNode* node, int &counter,int k, int &ksmallest){
        if(!node || counter>=k){
            return;
        }

        //traversing left tree
        inorder(node->left,counter,k,ksmallest);
        counter++;
        if(counter==k){
            ksmallest=node->val;
            return;
        }
        inorder(node->right,counter,k,ksmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter=0;
        int ksmallest=INT_MIN;
        inorder(root,counter,k,ksmallest);
        return ksmallest;
    }
};
//striver code for both smallest and largest

class Solution {
private:
    // Helper function to perform reverse inorder
    // traversal to find Kth largest element
    void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;

        // Traverse right subtree
        reverseInorder(node->right, counter, k, kLargest);

        // Increment counter after
        // visiting right subtree
        counter++;

        // Check if current node
        // is the Kth largest
        if (counter == k) {
            kLargest = node->val;
            return;
        }

        // Traverse left subtree if
        // Kth largest is not found yet
        reverseInorder(node->left, counter, k, kLargest);
    }

    // Helper function to perform inorder
    // traversal to find Kth smallest element
    void inorder(TreeNode* node, int& counter, int k, int& kSmallest) {
        if (!node || counter >= k) return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k) {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }

public:
    pair<int, int> findKth(TreeNode* root, int k) {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        // Counter to track visited nodes
        int counter = 0; 

        // Find Kth smallest element
        // (perform inorder traversal)
        inorder(root, counter, k, kSmallest);
        
        // Reset counter for Kth largest element
        counter = 0; 
        // Find Kth largest element
        // (perform reverse inorder traversal)
        reverseInorder(root, counter, k, kLargest);

        return make_pair(kSmallest, kLargest);
    }
};

int main() {
        
    Solution solution;

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
                                
                            
