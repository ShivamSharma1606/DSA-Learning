//brute force approach
/*
using hash map
tc: 0(2n) and sc: 0(N) + [O(n)]->required for question
https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/
//ss on samNotes and algo
*/


//optimal approach
//tc : O(3n) and sc: O(N) [for question]

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */
void insertCopyInBetween(Node *head){
	Node *temp=head;

	while(temp!=NULL){
		Node *copyN= new Node(temp->data);
		copyN->next=temp->next;
		temp->next=copyN;
		temp=temp->next->next;
	}
}

void connectRandomPointer(Node *head){
	Node *temp=head;

	while(temp!=NULL){
		Node *copyN=temp->next;
		if(temp->random){
			copyN->random=temp->random->next; //it point the copy random pointer to copy of temp random not of original temp->next
		}
		else {
			copyN->random= nullptr;
		}
		temp=temp->next->next;
	}
}

Node *getCopyList(Node *head){
	Node *dummyN=new Node(-1);
	Node *res=dummyN;
	Node *temp=head;

	while(temp!=NULL){
		res->next=temp->next;
		res=res->next;
		temp->next=temp->next->next;
		temp=temp->next;
	}
	return dummyN->next;
}

Node *cloneLL(Node *head){
	// Write your code here
	insertCopyInBetween(head);
	connectRandomPointer(head);
	return getCopyList(head);
}

int main(){
    
}
