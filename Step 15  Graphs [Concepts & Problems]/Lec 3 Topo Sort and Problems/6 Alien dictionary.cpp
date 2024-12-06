/*
dicitionay is not possible if
1. if their is any cyclic dependency
2. if larger same string is before same smaller string(with same charcter)
        eg:     s1=  bcda
                s2=  bcd
        It is not possible s2 has to be come before s1 as both the string have the same
        character
*/

#include<bits/stdc++.h>
using namespace std;

// work for multiple componets as well
vector<int> topologicalSort(int n, vector<vector<int>> &adj)
{
    // finding the indegree of all node
    vector<int> indegree(n, 0);
    for (int i = 0; i < adj.size(); i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    // push all node have indegree zero(dag have alway aleaset one node have 0 degree)

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty())
    {

        int node = q.front();
        topo.push_back(node);
        q.pop();

        for (auto it : adj[node])
        {

            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
    // number of words in dicitionary can be less than k
    vector<vector<int>> adj(k);
    int dsize = dictionary.size();

    for (int i = 0; i < dsize - 2; i++)
    {
        string str1 = dictionary[i];
        string str2 = dictionary[i + 1];

        int minlen = min(str1.size(), str2.size());

        for (int ptr = 0; ptr < minlen; ptr++)
        {
            if (str1[ptr] != str2[ptr])
            {
                adj[str1[ptr] - 'a'].push_back(str2[ptr] - 'a'); // - 'a' because to convert them into integers
                break;                                           // it is important because if we get distinct element it start comparing
            }
        }
    }

    vector<int> topo = topologicalSort(k, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans = ans + char(it + 'a');
    }

    return ans;
}