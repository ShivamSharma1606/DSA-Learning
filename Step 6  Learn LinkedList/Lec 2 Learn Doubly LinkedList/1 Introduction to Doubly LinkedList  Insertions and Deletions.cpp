#include<bits/stdc++.h>
using namespace std;
//creating the node for DLL

class Node{
    public:
    int data;
    Node* next; 
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data =data1;
        next =next1;
        back =back1;
    }

    //optional multiconstructor
    Node(int data1){
        data =data1;
        next =nullptr;
        back =nullptr;
    }

};

Node* convert2Arr(vector<int> &arr){
    Node *head= new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;    
}

Node * deleteHead(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node *prev= head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;

    free(prev);
    return head;
}

Node *deleteTail(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;        
    }
    Node *newTail=temp->back;
    temp->back=NULL;
    newTail->next=NULL;
    delete temp;
    return head;
}

Node *deleteKth(Node *head, int k){
    if(head==NULL){
        return NULL;
    }

    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }

    Node *b=temp->back; //b mean back
    Node *f=temp->next; //f mean front

    if(b==NULL && f==NULL){
        return NULL;
    }else if(b==NULL){
        return deleteHead(head);
    }else if(f==NULL){
        return deleteTail(head);
    }
    b->next=f;
    f->back=b;
    delete temp;
    return head;
}

void deleteNode(Node *temp){
    Node *f=temp->next;
    Node *b=temp->back;

    if(temp->next==NULL){
        b->next=nullptr;
        delete temp;
        return; // this return is use because so we do not execute the next lines of code   
    }

    f->back=b;
    b->next=f;
    free(temp);
}

Node* insertBHead(Node *head, int k){
    Node *newHead= new Node(k, head, nullptr);
    head->back=newHead;
    return newHead;
}

Node *insertBTail(Node *head, int k){
    if(head->next==NULL){
        return insertBHead(head,k);
    }

    Node *temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    Node *back=temp->prev;
    Node *newNode= new Node(k,back,temp);
    back->next=newNode;
    temp->prev=newNode;
    return head;
}

Node *insertK(Node *head, int val , int pos){
    if(k==1){
        return insertBHead(head,val);
    }
    Node *temp=head;
    int cnt=0;
    while(temp->next!=NULL){
        cnt++;
        if(pos==cnt){
            break;
        }
        temp=temp->next;
    }
    Node *prev=temp->back;
    Node newNode=new Node(val,temp, prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;

}

void inesertNode(Node*node ,int val){
    Node*prev = node->back;
    Node*newNode = new Node(val , node, prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){ 
    vector<int> arr= { 1,5,3,2,6,9};
    //conver the array to double linked list
    Node * head=convert2Arr(arr);

    //detete the head of dll
    head=deleteHead(head);
    
    //delete the tail of dll
    head=deleteTail(head);

    //delete the kth element
    int k;
    cin>> k;
    head=deleteKth(head,k);

    //delete the given node
    deleteNode(head->next);

    //insertion before the head

    //insertion before the tail

    //insertion at kth position

    //insert the given node
    


    // some interestin questions
    /*
    check some are different
    Insertion before the head: https://tinyurl.com/58fyn6d8
    Insert after a given Node: https://tinyurl.com/26yh8tv7
    Insert at end: https://tinyurl.com/4a9e8ceu
    https://www.naukri.com/code360/problems/insertion-in-doubly-linked-list_4609682    
    */
    

}