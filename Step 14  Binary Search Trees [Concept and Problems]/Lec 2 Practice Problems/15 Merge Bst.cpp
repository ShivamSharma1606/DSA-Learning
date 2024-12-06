// https://leetcode.com/problems/merge-bsts-to-create-single-bst/


class simplecodeWithMoreTC {
public:
    set <int> unique;

    bool checkLeaf(TreeNode* node) { return !node->left && !node->right; }

    void leafy(TreeNode* Node, vector<TreeNode*>& leafNode) {
        if (!Node)
            return;

        unique.insert(Node->val);
        if (checkLeaf(Node)) {
            leafNode.push_back(Node);
        }
        leafy(Node->left, leafNode);
        leafy(Node->right, leafNode);
    }
    
    
    bool countValidNodes(TreeNode *root, long min = INT_MIN, long max = INT_MAX)
    {
        if (root == NULL)
            return true;
        if (root->val >= max || root->val <= min)
        {
            return false;
        }
        return countValidNodes(root->left, min, root->val) && countValidNodes(root->right, root->val, max);
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if(trees.size() == 1)    return trees[0];
        // to store all the leafNodes
        vector<TreeNode*> leafNode;
        //{value of root, whole }
        unordered_map<int, TreeNode*> root;

        // storing the root and unique value
        for (auto it : trees) {
            root[it->val] = it;
        }

        // finding the leaf of all root
        for (auto it : trees) {
            leafy(it, leafNode);
        }

        // merging the leaf nodes with root
        for (int i = 0; i < leafNode.size(); i++) {
            auto rootFinder = root.find(leafNode[i]->val);

            if (rootFinder == root.end())
                continue;

            TreeNode* leaf = leafNode[i];
            TreeNode* rootNode = rootFinder->second;

            leaf->left = rootNode->left;
            leaf->right = rootNode->right;

            root.erase(rootFinder);
        }

        
        // Return the last remaining root if only one tree exists
        if (root.size() == 1) {
            TreeNode* finalTree = root.begin()->second;
            int count = countNodes(finalTree);
            if (countValidNodes(finalTree) && count == unique.size()) {
                return finalTree;
            }
        }
        return nullptr;
    }
};


//! recommended
class TrickyButCompetitive {
public:
    // Set to store all unique values from the trees
    unordered_set<int> uniqueNodeValues;
    
    // Map to store the tree roots keyed by their root value
    unordered_map<int, TreeNode*> rootNodes;
    
    // List to store leaf nodes for merging
    vector<TreeNode*> leafNodes;

    // Function to add leaf nodes to the leafNodes vector and uniqueNodeValues set
    void addLeafNode(TreeNode* node) {
        if (node != nullptr) {
            uniqueNodeValues.insert(node->val);
            // If the node is already a root node, add it to leafNodes
            if (rootNodes.count(node->val))
                leafNodes.push_back(node);
        }
    }

    // Function to count the valid nodes in the current tree by checking BST properties
    int countValidNodes(TreeNode* node, int minVal = INT_MIN, int maxVal = INT_MAX) {
        if (node == nullptr || node->val <= minVal || node->val >= maxVal)
            return 0;
        // Recursively count nodes while ensuring valid BST properties
        return 1 + countValidNodes(node->left, minVal, node->val) + 
                   countValidNodes(node->right, node->val, maxVal);
    }

    // Function to attempt to merge the trees and return the final merged tree (if valid)
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // Store all root nodes in the rootNodes map
        for (auto& tree : trees)
            rootNodes[tree->val] = tree;

        // Iterate through each tree to insert unique values and add leaves
        for (auto& tree : trees) {
            uniqueNodeValues.insert(tree->val);
            addLeafNode(tree->left);
            addLeafNode(tree->right);
        }

        // Try to merge the leaf nodes with the corresponding trees
        for (auto leaf : leafNodes) {
            auto rootIt = rootNodes.find(leaf->val);
            // If no corresponding tree root exists, return nullptr
            if (rootIt == end(rootNodes))
                return nullptr;
                /*
                !we use nullptr because this is ranged based for loop not index type
                if we encontered nullptr then it move to the next part[next auto leaf] and not return the value for the function
                if it is normal for loop then it don't continue for other statement and return nullptr as a 
                result for the function canMerge
                */
            // Merge the leaf node with the root node
            leaf->left = rootIt->second->left;
            leaf->right = rootIt->second->right;
            // Remove the merged root from the map
            rootNodes.erase(rootIt);
        }

        // If only one tree remains and all nodes are valid in the final BST, return the root
        return rootNodes.size() == 1 && 
               countValidNodes(begin(rootNodes)->second) == uniqueNodeValues.size() 
               ? begin(rootNodes)->second : nullptr;
    }
};