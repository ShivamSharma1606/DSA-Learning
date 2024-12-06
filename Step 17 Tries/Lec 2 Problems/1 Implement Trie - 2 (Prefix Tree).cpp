#include <bits/stdc++.h>
struct Node
{
    // array of lenght 26
    Node *link[26];
    int cntPrefix = 0;
    int cntEndWith = 0;

    bool containValue(char ch)
    {
        // if value exist return true other wise return false;
        return (link[ch - 'a'] != NULL);
    }

    // create a new node and link the new node
    void creation(char ch, Node *create)
    {
        link[ch - 'a'] = create;
    }

    // Going to the next node

    Node *linking(char ch)
    {
        return link[ch - 'a'];
    }

    void IncreasePrefix()
    {
        cntPrefix++;
    }

    void IncreaseEnd()
    {
        cntEndWith++;
    }

    void DecreasePrefix()
    {
        cntPrefix--;
    }

    void DecreaseEnd()
    {
        cntEndWith--;
    }
};
class Trie
{

private:
    // defining the root
    Node *root;

public:
    Trie()
    {
        // Initializing the root
        root = new Node();
    }

    void insert(string &word)
    {
        // creating the node
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            // checking value exist or not
            if (!node->containValue(word[i]))
            {
                // if value does't not exist then create the node
                node->creation(word[i], new Node());
            }
            node = node->linking(word[i]);
            // Increasing the value of prefix
            node->IncreasePrefix();
        }

        // At the end of the node increaese the cntEndWith
        node->IncreaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {

            if (node->containValue(word[i]))
            {
                node = node->linking(word[i]);
            }
            else
            {
                return 0;
            }
        }

        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word)
    {

        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {

            if (node->containValue(word[i]))
            {
                node = node->linking(word[i]);
            }
            else
            {
                return 0;
            }
        }

        return node->cntPrefix;
    }

    void erase(string &word)
    {

        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {

            if (node->containValue(word[i]))
            {
                node = node->linking(word[i]);
                node->DecreasePrefix();
            }
            else
            {
                return;
            }
        }

        node->DecreaseEnd();
    }
};
