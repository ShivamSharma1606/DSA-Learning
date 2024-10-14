//brute force approach
/*
1 find the length of the ll
2 find the n/2 element (not n/2 +1 it give middle element ) i.e element before middle element
3 conncet the n/2->next  to the n/2->next->next
4 middle element will be deleted
5(optiona) you can also free the middle element 
tc=(n + n/2) and sc =1
*/

//optimal approach using TortoiseHare Method
//tc = n/2 and sc=1


#include <bits/stdc++.h>
/*
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
*/

Node* deleteMiddle(Node* head){
    // Write your code here.
    if (head==NULL || head->next==NULL){
        return NULL;
    }

    Node *slow=head;
    Node *fast=head;
    fast=fast->next->next;//this is becuase to find the element before middle

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node *middle=slow->next;
    slow->next=slow->next->next;
    delete middle;
    return head;
}
