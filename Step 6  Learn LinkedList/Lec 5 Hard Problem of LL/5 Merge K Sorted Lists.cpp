//brute force approach
// using array and sorting and convert to linked list
//tc:m + mlogm +m (m=n*k(no. of ll))

//better approach using two sorted linked list
//tc: n*(k*(k+1)/2) approx n^3

//optimal approach
//using min_head(priority queue)
//tc: k*logk + n*k*logk and sc: k
//one of the best and tough question
//please study priority queue before doing quesion


#include<bits/stdc++.h>
/*
Following is the class structure of the Node class:

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
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* mergeKLists(vector<Node*> &listArray){
    
    priority_queue<pair<int,Node*>,
    vector<pair<int,Node*>>, greater<pair<int, Node*>>> pq;

    

    for(int i=0; i<listArray.size();i++){
        if(listArray[i]){
            pq.push({listArray[i]->data,listArray[i]}); //entering the fist node of each ll and its value
        }
    }

    Node *dummyNode = new Node(-1);
    Node *temp=dummyNode;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data,it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
}
