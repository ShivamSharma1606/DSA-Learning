#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *link[26];

    //checking value exist or not
    bool valueContain(char ch){
        return link[ch - 'a']!=NULL;
    }

    //creating the node if not exist
    void put(char ch, Node *create) { 
        link[ch - 'a'] = create; 
    }

    //getting the value of next node
    Node *get(char ch){
        return link[ch - 'a'];
    }
};


int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int cnt=0;
    for(int i=0;i<s.size();i++){
        Node *node=root;
        for(int j=i;j<s.size();j++){
            
            if(!node->valueContain(s[j])){
                cnt++;
                node->put(s[j], new Node());
            }
            node= node->get(s[j]);
        }
    }
    //+1 becaue we have to consider empty string also in cnt
    return cnt+1;
    
}