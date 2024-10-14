/*
brute force approach
1. fine the size(using traversing the linked list) - k
2. remove the node by traversing
3. link the previous node to that given node
4. we have to make a special case for k==n i.e when delete value is head then we shift the head by one position
sc = o(n)+ o(n-k)
*/

/*
optimal solution: o(n)
*/

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


Node* removeKthNode(Node* head, int k)
{
    Node *fast=head;
    Node *slow=head;

    for(int i=0;i<k;i++) fast=fast->next;

    if(fast==NULL){
        return head->next;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    
    Node *dele=slow->next;
    slow->next=slow->next->next;
    free(dele);
    return head;
}


int main(){
    
}

