#include <bits/stdc++.h>

struct Node
{

    Node *link[26];
    bool flag;

    // return true if value eixt
    bool containValue(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }

    // creating the new node if not exist
    void put(char ch, Node *create)
    {
        link[ch - 'a'] = create;
    }

    // geting the next node
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool endWith()
    {
        return flag;
    }
};

class Tries
{
private:
    Node *root;

public:
    Tries()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++)
        {
            // if value does't exist
            if (!temp->containValue(word[i]))
            {
                temp->put(word[i], new Node());
            }

            temp = temp->get(word[i]);
        }

        temp->setEnd();
    }

    bool CheckingPrefixExist(string word)
    {
        Node *temp = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (temp->containValue(word[i]))
            {
                temp = temp->get(word[i]);
                if (temp->endWith() == false)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{

    // creating the object tri
    Tries tri;

    for (auto &it : a)
    {
        tri.insert(it);
    }

    string longest = "";
    for (auto &it : a)
    {

        if (tri.CheckingPrefixExist(it))
        {
            if (it.size() > longest.size())
                longest = it;
            else if (it.size() == longest.size() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
        return "None";
    return longest;
}