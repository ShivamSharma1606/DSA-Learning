#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[2];

    bool contianValue(int num) { return link[num] != NULL; }

    void put(int num, Node* create) { link[num] = create; }

    Node* get(int num) { return link[num]; }
};

class Tries {
private:
    Node* root;

public:
    // creating the constructor
    Tries() { root = new Node(); }

    void insert(int num) {
        Node* temp = root;
        for (int i = 31; i >= 0; i--) {
            // finding the i th bit
            int bit = (num >> i) & 1;

            if (!temp->contianValue(bit)) {

                temp->put(bit, new Node());
            }

            temp = temp->get(bit);
        }
    }

    int getMax(int num) {
        Node* temp = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // finding the compliment of the bit
            if (temp->contianValue(1 - bit)) {

                // updating the maximum xor
                maxNum |= (1 << i);
                temp = temp->get(1 - bit);
            } else {
                temp = temp->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ; // offline quires concept

        int q = queries.size();
        for (int i = 0; i < q; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(oQ.begin(), oQ.end());

        vector<int> ans(q, 0);
        int n = nums.size();
        int ind = 0;
        
        Tries trie;
        
        for (int i = 0; i < q; i++) {
            int ai = oQ[i].first;  
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;

            while (ind < n && nums[ind] <= ai){
                trie.insert(nums[ind]);
                ind++;
            }

            //no value is inserted
            if(ind==0)  ans[qInd]=-1;
            else ans[qInd]=trie.getMax(xi);

        }

        return ans;
    }
};