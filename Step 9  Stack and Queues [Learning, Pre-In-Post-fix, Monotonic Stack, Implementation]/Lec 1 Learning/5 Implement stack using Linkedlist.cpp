#include <bits/stdc++.h>

// Following is the class structure of the Node class :

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

class Stack
{
    // Write your code here

public:
    Node *top;
    int size;
    Stack()
    {
        // Write your code here
        top = NULL;
        size = 0;
    }

    int getSize()
    {
        // Write your code here
        return size;

        // or

        // Node *temp=top;
        // int cnt=0;
        // while(temp!=NULL){
        //     cnt++;
        //     temp=temp->next;
        // }
        // return cnt;
    }

    bool isEmpty()
    {
        // Write your code here
        if (top == NULL)
            return true;
        return false;
    }

    void push(int data)
    {
        // Write your code here
        Node *temp = new Node(data, top);
        top = temp;
        size++;
    }

    void pop()
    {
        // Write your code here
        if (isEmpty())
            return;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int getTop()
    {
        // Write your code here
        if (!isEmpty())
            return top->data;
        return -1;
    }
};