#include<bits/stdc++.h>
using namespace std;
//creating the node

struct Node{ //we can also use class instead of struct which is better
    public:
    int data;
    Node* next; //we can also use link or any variable for next

    public:
    Node(int data1, Node* next1){
        data =data1;
        next =next1;
    }

    //optional multiconstructor
    Node(int data1){
        data =data1;
        next =nullptr;
    }

};

//converting the array into linked list
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

//finding the length of linked list

int lengthLinkedList(Node* head){

    Node* temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next; 
    }
    return count;
}

int findingelement(Node* head,int x){

    Node* temp=head;
    while(temp){
        if(temp->data==x)    return 1;
        temp=temp->next; 
    }
    return 0;
}


int main(){

    //converting the array into linked list
    vector<int> arr ={ 12,5,8,7};
    Node* head=  convertArr2LL(arr);
    cout<< head->data;

    //traversing the linked list
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }

    //length of linked list
    cout<< lengthLinkedList(head);

    //checking present of an element
    int x;
    cout<<"Enter the value of element to be search";
    cin>>x;
    cout<<findingelement(head, x);
}