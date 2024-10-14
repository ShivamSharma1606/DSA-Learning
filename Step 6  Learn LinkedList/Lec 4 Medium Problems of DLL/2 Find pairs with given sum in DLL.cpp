//brute force appraoch
//algo ss in samnotes
/*
1 take two temp1=head and temp2=head->next
2 traverse the  element of temp1 with temp2 i.e compare each element of temp1 with all element. Using the while loop of temp1
3 compare the sum if equal to given store in dataStructure
4 else increase the value of temp2
5 after temp 2 while loop increase the value of temp1 

tc= n^2 and sc=1
*/

//optimal approach
//tc = 2n and sc=1

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *findingLast(Node *head){
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>> ans;
    if(head==NULL) return ans;

    Node *left=head;
    Node *right=findingLast(head);

    while(left->data<right->data){
        if(left->data+right->data==k){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }else if(left->data+right->data>k){
            right=right->prev;
        }else{
            left=left->next;
        }
    }
    return ans;
}
