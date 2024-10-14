//optimal approach
// tc: 2n and sc: 1

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node* reverseLinkedList(Node *head)
{
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

Node* kthElementFinder(Node *temp,int k){

    k-=1;
    while(k>0 && temp!=NULL){
        temp=temp->next;
        k--;
    }
    return temp;
}

Node* kReverse(Node* head, int k) {

    Node *temp=head;   
    Node *prevNode=NULL;

    while(temp!=NULL) {
        Node *kthNode=kthElementFinder(temp,k);
        if(kthNode==NULL){
            if(prevNode)    prevNode->next=temp;
            break;
        }

        Node *nextNode=kthNode->next;
        kthNode->next=NULL;
        reverseLinkedList(temp);

        if(head==temp){
            head=kthNode;
        }else{
            prevNode->next=kthNode;
        }

        prevNode=temp;
        temp=nextNode;
    }
    return head;
}