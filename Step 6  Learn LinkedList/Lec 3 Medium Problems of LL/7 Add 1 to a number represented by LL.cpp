/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/


//brute force approach
/*
prons: no extra space required i.e o(1)
cons: tampering of data and more tc
*/
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

Node *addOne(Node *head)
{
    //O(n)
    head = reverseLinkedList(head);
    Node *temp=head;
    int carry=1;

    //O(n)
    while(temp!=NULL){
        temp->data=temp->data+carry;

        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }

    if(carry==1){
        head=reverseLinkedList(head);
        Node *newNode= new Node(1);
        newNode->next=head;
        return newNode;
    }

    //O(n)
    head=reverseLinkedList(head);
    return head;
}
rute force approach 0(3n)

//optimal approach
/*
prons: no tampering of data and less tc
cons: more space required
*/

 