#include<bits/stdc++.h>
using namespace std;
struct Node {
    // creating an array of length 26[26 alphabhatic character]
    Node* link[26];
    bool flag = false;

    bool containValue(char ch) {
        // if value exist return true otherwiser return false
        return link[ch - 'a'] != NULL;
    }

    // Create a new Node and return a pointer of it
    void put(char ch, Node* create) {
        // For eg char is 'c' then at index 3 we create a new node
        link[ch - 'a'] = create;
    }

    // Going to the reference Node
    Node* getNext(char ch) { return link[ch - 'a']; }

    // setting the last node as true
    void setEnd() { flag = true; }

    // checking the last Node have true or false value
    bool IsEnd() { return flag; }
};

class Trie {
private:
    // defining the root Node
    Node* root;

public:
    // constructor for creating a NULL Root
    Trie() {
        // Intializing the root node[Null Node]
        root = new Node();
    }

    void insert(string word) {
        int n = word.size();
        Node* temp = root;

        for (int i = 0; i < n; i++) {
            // if value doesn't exist
            if (!temp->containValue(word[i])) {
                // then crate a new node
                temp->put(word[i], new Node());
            }
            // move to the next node
            temp = temp->getNext(word[i]);
        }

        // after inserting all the element set the last node true
        temp->setEnd();
    }

    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (!temp->containValue(word[i])) {
                return false;
            }
            temp = temp->getNext(word[i]);
        }

        // also check last flag is true or Not
        return temp->IsEnd();
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!temp->containValue(prefix[i])) {
                return false;
            }
            temp = temp->getNext(prefix[i]);
        }

        return true;
    }
};

int main(){

}