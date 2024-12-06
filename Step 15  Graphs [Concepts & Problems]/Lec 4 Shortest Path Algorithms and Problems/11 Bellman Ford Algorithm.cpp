/*
Bellman Ford Algorrithm only work for directed graph.
If you want to work for un-directed graph then you have to convert it into directed graph
It also work for negative edges but not for negative cycle

Since in a graph of N nodes, in worst case, you will take N-1 edges to reach from the first to the last,
thereby we iterate for N-1 iterations.
*/

//! time complexity : V*E

//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int n, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(n, 1e8);
        dist[src] = 0;

        // in bellman ford we do n-1 iteration
        for (int i = 0; i < n - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e8 && dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // If graph have negative cycle then it will have still update on Nth cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[v] > dist[u] + wt)
            {
                return {-1};
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int N, m;
        cin >> N >> m;

        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends