//optimal approach
//tc: 2n and sc: 1


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


//homework do same question for array
Node* findLastNode(Node *temp, int diff){
     
     int cnt=1;
     while(temp != NULL){
          if(cnt == diff)     return temp;
          cnt++;
          temp=temp->next;
     }
     return temp;
}

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL || k==0){
          return head;
     }

     int len=1;
     Node *tail=head;
     while(tail->next!=NULL){
          len++;
          tail=tail->next;
     }

     if(k%len==0) return head;
     else{
          k=k%len;
          tail->next=head;
          Node *newLastNode=findLastNode(head,len-k);
          head=newLastNode->next;
          newLastNode->next=NULL;
          return head;
     }
}