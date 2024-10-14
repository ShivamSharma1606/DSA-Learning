// brute force approach
/*
1. first we create the map where we store the node and its number of visit  (map <Node * ,int> mpp)
2. any time we find the visit(int) as 2 then we return that their is a loop(true)
3. else return false
4. checking and traversing has been done in one while loop
tc = o(n) X 2logn
sc = o(n)
*/

// optimal approach using TortoiseHare Method
//  tc =0(n) and sc=1

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

bool detectCycle(Node *head)
{
    //	Write your code here
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}