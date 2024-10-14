#include<bits/stdc++.h>
class LRUCache
{
public:
    class node{
        public:
        int key;
        int val;

        node *next;
        node *prev;

        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };

    node *head =  new node (-1,-1);
    node *tail =  new node (-1,-1);
    int cap;
    unordered_map<int,node*> mpp;

    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;

    }

    void deletenode(node *delNode){
        node *delp=delNode->prev;
        node *deln=delNode->next;
        delp->next=deln;
        deln->prev=delp;
    }

    void addnode(node *addN){
        node *temp=head->next;
        addN->next=temp;
        addN->prev=head;
        head->next=addN;
        temp->prev=addN;
    }

    int get(int key)
    {
        // Write your code here
        if(mpp.find(key)!=mpp.end()){
            node *temp=mpp[key];
            int res=temp->val;
            deletenode(temp); //do not delete the node only change the link
            addnode(temp);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mpp.find(key)!=mpp.end()){
            node *temp=mpp[key];
            mpp.erase(key);
            deletenode(temp);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key , value));{
            mpp[key]=head->next;
        }
    }
};
