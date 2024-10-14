//brute force approach
/*
1. we create a stack data structure
2. push the element in the stack
3. pop the elment which is the last element of ll
4. replace with the first element of the link list
tc= o(2n) and sc=1
*/

//optimaial approach
//iterative approach

/****************************************************************

    Following is the class structure of the Node class:

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
        

*****************************************************************/

//iterative approach
Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node *temp=head;
    Node *prev=NULL;

    while (temp != NULL) {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

//recursive approach
Node* reverseLinkedList(Node *head)
{
    if (head==NULL || head->next==NULL){
        return head;
    }

    Node *newHead= reverseLinkedList(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}