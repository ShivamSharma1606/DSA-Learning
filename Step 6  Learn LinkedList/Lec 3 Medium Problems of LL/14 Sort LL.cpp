//brute force approach
/*
1 create an array
2 push all the element of the ll into array
3 applying the sorting algorithm
4 update the value of the ll

tc = n + nlogn(sorting algo) + n
sc = n
*/

//optiomal approach using merge sort

//tc = (n+n/2)logn and sc =1

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/


Node *findMiddle(Node *head) {
    // Write your code here
    Node *slow=head;
    Node *fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *mergeTwoList(Node *list1, Node *list2){
	Node *dummyList = new Node(-1);
	Node *temp=dummyList;
	while(list1!=NULL &&  list2!=NULL){
		if(list1->data<list2->data){
			temp->next=list1;
			temp=list1;
			list1=list1->next;
		}else{
			temp->next=list2;
			temp=list2;
			list2=list2->next;
		}
	}
	if(list1) temp->next=list1; //we do not need looping because like array because element are already link in ll
	else	temp->next=list2;
	return dummyList->next;
}

Node *sortLL(Node *head) {
    if(head==NULL || head->next==NULL){
		return head;
	}

	Node *middle=findMiddle(head);
	Node *right=middle->next;
	middle->next=nullptr;
	Node *left=head;

	left=sortLL(left);
	right=sortLL(right);
	return mergeTwoList(left,right);
}
