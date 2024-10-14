//brute force apprach
//ss in samNotes
/*
1 push all the element of the ll using temp1(for forward dirn) and temp2(for downward dirn)
2 sort the array 
3 convert the array into vertical ll(not horizontal)
tc: n*m + nmlog(nm) + n*m(n for rows and m for child)
sc: 2(n*m) one for array and one for ll
*/

//optimal approach
//same like merge two sorted ll
//tc: n+ 2m =approx 0(2nm) and sc:n

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *list1, Node*list2){
	Node *dummyNode=new Node(-1);
	Node *res=dummyNode;
	while(list1!=NULL && list2!=NULL){
		if(list1->data<list2->data){
			res->child=list1;
			res=list1;
			list1=list1->child;
		}else{
			res->child=list2;
			res=list2;
			list2=list2->child;
		}
		res->next=nullptr;		
	}
	if(list1) res->child=list1;
	else res->child=list2;
	if(dummyNode->child)	dummyNode->child->next=nullptr;
	return dummyNode->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)	return head;

	Node *mergeHead=flattenLinkedList(head->next);
	head=merge(head,mergeHead);
	return head;
}

int main(){
    
}

