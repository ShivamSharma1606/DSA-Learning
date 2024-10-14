//brute force approach
/*
1 find the length of link list let n
2 find the middle element by n/2 +1
3 traverse to the n/2 element and return that element 
tc = 0(n+n/2)
sc =1
*/

//optimal approach
//o(n/2)
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
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node *findMiddle(Node *head) {
    // Write your code here
    Node *slow=head;
    Node *fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

