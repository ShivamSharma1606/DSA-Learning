#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    // Converting edge list to adjacency list
    vector<vector<int>> adj(n);
    for (auto &edge : edges)
    {
        //-1 because indexing start from 1 and code is written for 0
        adj[edge.first - 1].push_back(edge.second - 1);
    }

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

    // If the topological sort size is not equal to the number of nodes,
    // it means there is a cycle
    return topo.size() != n ? 1 : 0;
}