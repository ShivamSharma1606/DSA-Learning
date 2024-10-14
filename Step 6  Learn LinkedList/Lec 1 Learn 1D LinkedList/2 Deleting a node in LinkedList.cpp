#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next =next1;
    }


    Node(int data1){
        data =data1;
        next =nullptr;
    }

};

Node* convertArr2LL(vector<int>  &arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp; 
    }
    return head;
}

Node* removingtheHead(Node* head){
    if(head==NULL) return head;
    else{
        Node temp* =head;
        head=head->next;
        delete temp; //our head is already remove in above step but it is used to remove the tempHead from the memory for cleaning
        return head;
    }
}

Node* remmovingTail(Node* head){
    if(head==NULL   || head->next==NULL)  return head;
    Node *temp=head;
    while(temp->next->next!=null){
        temp=temp->next;

    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node * removingK(Node * head,k){
    if(head==NULL)    return head;
    if(k==0){
        Node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=-1;
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;    
}

Node * removingSpecific(Node * head,el){
    if(head==NULL)    return head;
    if(head->data==el){
        Node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        
        if(temp->data==el){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;    
}

Node* insertHead(Node *head, int val){
    Node * temp= new Node(val,head);
    return head;
}

Node* insertTail(Node *head, int val){
    if(head==NULL){
        return new Node(val);
    }else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next; 
        }
        Node* newNode= new Node(val);
        temp->next=newNode;
        return head;
    }
}

Node* insertK(Node *head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(int val);
        }else{
            return head;
        }
    }
    //same alternative way to insert at head
    if(k==1){
        return new Node(val , head);
    }

    int cnt=0;
    Node *temp=head;
    while(temp!=NULL){
        cnt++;
        if( cnt==(k-1)){
            Node *newNode= new Node(val,temp->next);
            temp->next=newNode;
            break;

        }else{
            temp=temp->next;
        }
    }
    return head;
}

Node* insertBeforeValue(Node *head, int val, int k,int val){
    if(head==NULL){
        return NULL;
    }

    //same alternative way to insert at head
    if(head->data==val){
        return new Node(val , head);
    }

    Node *temp=head;
    while(temp->next!=NULL){
        
        if( temp->next->data==val){
            Node *newNode= new Node(val,temp->next);
            temp->next=newNode;
            break;

        }else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    //converting the array into linked list
    vector<int> arr ={ 12,5,8,7};
    Node* head=  convertArr2LL(arr);
    cout<< head->data;

    //removing the head of LL
    head=removingtheHead(head);

    //removing the tail of LL
    head=removingTail(head);

    //removing the specific element by position;
    int k;
    cout<<"Enter the position want to delete";
    cin>> k;
    head=removingK(head,k);

    //removing the specific value element
    
    cout<<"Enter the position want to delete";
    cin>> k;
    head=removingSpecific(head,k);

    //inserting the head
    int val;
    cout<<"Enter the new value of head to be insert";
    cin>> val;
    head= insertHead(head,val);

    //inserting the tail
    head= insertTail(head,val);

    //inserting at specific position
    cout<<"Enter the new value of k th position to be insert";
    cin>> k;
    head=insertK(head,val, k);

    //insert the node before specific value
    cout<<"Enter the new value of k th position to be insert";
    cin>> k;
    head=insertBeforeValue(head,val, k);


}

//https://www.naukri.com/code360/problems/delete-node-in-a-linked-list_1105578?leftPanelTabValue=SUBMISSION
//interesting problem   