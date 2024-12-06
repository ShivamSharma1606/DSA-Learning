// find the shortest path from source node to each node and select the neigbour node which have less weight
//  *]   priority_queue <Type, vector<Type>, ComparisonType > min_heap;(way to implement min heap)
//  ? does not work for negative weight or negative cycle
//  ! tc:  E log V

#include <bits/stdc++.h>
using namespace std;

class TimeLimitExceed
{
    vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
    {

        // implementing the priority min-heap {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // creating the distance vector and initially mark their value as infinite

        vector<int> dist(vertices, INT_MAX);
        dist[source] = 0;

        // Entering the source node
        pq.push({0, source});

        while (!pq.empty())
        {

            auto it = pq.top();
            pq.pop();

            int wgt = it.first;
            int node = it.second;

            for (int i = 0; i < edges; i++)
            {
                if (vec[i][0] == node)
                {

                    int adjNode = vec[i][1];
                    int adjWeight = vec[i][2];

                    if (wgt + adjWeight < dist[adjNode])
                    {
                        dist[adjNode] = wgt + adjWeight;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
                else if (vec[i][1] == node)
                {
                    int adjNode = vec[i][0];
                    int adjWeight = vec[i][2];

                    if (wgt + adjWeight < dist[adjNode])
                    {
                        dist[adjNode] = wgt + adjWeight;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
        }

        return dist;
    }
};

//codestudio
#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    // creating the adjacency list
    vector<vector<pair<int, int>>> adj(vertices);
    // first converting into Adjacency List
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({w, v});
        // for undirected graph
        adj[v].push_back({w, u});
    }

    // implementing the priority min-heap {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // creating the distance vector and initially mark their value as infinite

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Entering the source node
    pq.push({0, source});

    while (!pq.empty())
    {

        auto it = pq.top();
        pq.pop();

        int wgt = it.first;
        int node = it.second;

        for (auto it : adj[node])
        {

            int adjNode = it.second;
            int adjWeight = it.first;

            if (adjWeight + wgt < dist[adjNode])
            {
                dist[adjNode] = adjWeight + wgt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}