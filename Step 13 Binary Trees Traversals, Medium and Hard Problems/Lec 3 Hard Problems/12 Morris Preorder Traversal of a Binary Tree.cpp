// first do the coding question 13 then come to 12

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    // Morris Travel
    // tc: n and sc:1 //sc=1 is the specialiy of this algo
    //  Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node *root)
    {
        // write code here
        vector<int> preorder;
        Node *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            { // if curr left is not exist
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right; // going right as much as possible
                }

                if (prev->right == NULL)
                {
                    prev->right = curr; // making a link between last right element and current element
                    preorder.push_back(curr->data);
                    curr = curr->left; // traversing downward and repeat same process of while
                }
                else
                {                       // mean their is already link between the last right element and current element
                    prev->right = NULL; // remove the link as now not needed
                    curr = curr->right; // now left part is already traverse go the left part
                }
            }
        }
        return preorder;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    Solution x; // Create an instance of Solution
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> res =
            x.preorder(root); // Call the preorder method on the Solution instance
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends