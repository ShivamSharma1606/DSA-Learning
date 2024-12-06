//! same complexity as dfs
// bipartite graph is a graph where each node have different color, and adjacent node can't have same color,the max color allowed is 2
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &color, int col)
{ // col: color

    color[node] = col;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (dfs(it, adj, color, !col) == false)
            {
                return false;
            }
        }
        // if adjacent node have same color
        else if (color[it] == color[node])
        {
            return false;
        }
    }

    return true; // if all condition satsify
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<vector<int>> adj(n);

    // converting into adj list
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (edges[i][j])
            {
                adj[i].push_back(j);
            }
        }
    }
    //their may be two color "0" or "1" or no color "-1"
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            //Initally start with color
            if (dfs(i, adj, color, 0) == false)
            {
                return false;
            }
        }
    }

    return true;
}