#include <bits/stdc++.h> 

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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Queue {
public:
    int size;
    Node *start;
    Node *end;
    Queue() {
        // Implement the Constructor
        start=NULL;
        end=NULL;
        size=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(start==NULL && end==NULL)    return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(isEmpty()){
            Node *temp= new Node (data);
            start=temp;
            end=temp;
        }else{
            Node *temp=new Node(data);
            end->next=temp;
            end=temp;
        }
        size++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())   return -1;
        Node *temp=start;
        int result=start->data;
        start=start->next;
        if(start==NULL){
            end=NULL;
        }
        delete temp;
        size--;
        return result;
    }

    int front() {
        // Implement the front() function
        if(isEmpty())   return -1;
        return start->data;
    }
};