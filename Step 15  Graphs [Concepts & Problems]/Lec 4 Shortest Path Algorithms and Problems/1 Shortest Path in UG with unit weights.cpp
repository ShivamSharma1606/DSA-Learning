// ? must must dry run

#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it.first])
        {
            toposort(it.first, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // n : vertices and m: edges

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];  // base node
        int v = edges[i][1];  // outward node
        int wt = edges[i][2]; // weight of the node

        adj[u].push_back({v, wt});
    }

    // step: 1 finding the topo sort
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposort(i, adj, visited, st);
        }
    }

    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = 1e9;
    }
    // distance of origin is zero(it can be user defined also)
    dist[0] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    // if we can't reach the node
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist;
}
