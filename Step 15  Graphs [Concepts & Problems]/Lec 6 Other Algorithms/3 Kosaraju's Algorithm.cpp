// strongly connected components is valid for only directed graph

/*
?Intitution
*consider a graph have more than one scc

*We can reach one ssc from other ssc
By definition, within each SCC, every node is reachable. So, if we start DFS from a node of SCC1 we can visit all the
nodes in SCC1 and via edge e1 we can reach SCC2. Similarly, we can travel from SCC2 to SCC3 via e2 and SCC3 to SCC4
via e3. Thus all the nodes of the graph become reachable.

*if we reverse the edges in graph
by reversing the SCC-connecting edges, the adjacent SCCs become unreachable. Now, the DFS will work in such a way,
that in one DFS call we can only visit the nodes of a particular SCC. So, the number of DFS calls will represent
the number of SCCs.

*/

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

void dfs2(int node, vector<int> &visited, vector<vector<int>> &adjT)
{

    visited[node] = 1;

    for (auto it : adjT[node])
    {
        if (!visited[it])
        {
            dfs2(it, visited, adjT);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // converting the edges into adj list
    vector<vector<int>> adj(v);
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    // creating the visited array

    vector<int> visited(v, 0);

    // for storing the starting time of node
    stack<int> st;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, st);
        }
    }

    // transpose of graph i.e reverse of graph
    vector<vector<int>> adjT(v);
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0; // marking all node unvisited again
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // for counting the fcc
    int scc = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            scc++;
            dfs2(node, visited, adjT);
        }
    }

    return scc;
}