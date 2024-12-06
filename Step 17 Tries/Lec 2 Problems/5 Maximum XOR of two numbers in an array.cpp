#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *link[2];

    bool contianValue(int num)
    {
        return link[num] != NULL;
    }

    void put(int num, Node *create)
    {
        link[num] = create;
    }

    Node *get(int num)
    {
        return link[num];
    }
};

class Tries
{
private:
    Node *root;

public:
    // creating the constructor
    Tries()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            // finding the i th bit
            int bit = (num >> i) & 1;

            if (!temp->contianValue(bit))
            {

                temp->put(bit, new Node());
            }

            temp = temp->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *temp = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            // finding the compliment of the bit
            if (temp->contianValue(1 - bit))
            {

                // updating the maximum xor
                maxNum |= (1 << i);
                temp = temp->get(1 - bit);
            }
            else
            {
                temp = temp->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Tries tries;

    for (auto &it : arr1)
    {
        tries.insert(it);
    }

    int maxi = 0;

    for (auto &it : arr2)
    {
        maxi = max(maxi, tries.getMax(it));
    }

    return maxi;
}