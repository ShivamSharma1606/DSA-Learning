// todo : please do it's dry run eg. in oneNotes
// do problem 3 first

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &visited, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &bridges, int timer)
{

    visited[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        // if neigbour is parent then no need to compare it's low
        if (it == parent)
            continue;
        if (!visited[it])
        {
            dfs(it, node, visited, tin, low, adj, bridges, timer);
            // finding the lowest neigbour excepth parent
            low[node] = min(low[node], low[it]);

            // node---it
            if (low[it] > tin[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            // finding the lowest neigbour excepth parent
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{

    // converting into adjacency matrix
    vector<vector<int>> adj(v);
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        // as the graph is undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(v, 0);
    vector<int> tin(v);
    vector<int> low(v);

    vector<vector<int>> bridges;
    int timer = 1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, visited, tin, low, adj, bridges, timer);
        }
    }

    return bridges;
}