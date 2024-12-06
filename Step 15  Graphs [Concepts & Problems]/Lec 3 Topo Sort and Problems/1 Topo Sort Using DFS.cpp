//! tc: same as dfs and sc: same + o(n)[stack]

#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st)
{

    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, visited, adj, st);
        }
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    vector<int> visited(v, 0);

    for (const auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
    }

    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }

    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}