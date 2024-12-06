/*
* Spanning Tree:
A spanning tree is a tree in which we have N nodes(i.e. All the nodes present in the original graph) and 
N-1 edges and all nodes are reachable from each other.

*Minimum Spanning Tree:
Among all possible spanning trees of a graph, the minimum spanning tree is the one for which the sum of all the 
edge weights is the minimum.

*Algorithms 
that help us to find the minimum spanning tree are Prim’s algorithm and the other is Kruskal’s algorithm.
*/

//? program to find the sum of mst


#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //priority queue
        priority_queue<pair <int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        // {node, weight}
        pq.push({0,0});
        
        vector<int> visited(V,0);
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(visited[node] == 1)  continue;
            visited[node] = 1;
            sum += wt;
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int wgt = it[1];
                
                if(!visited[adjNode]){
                    pq.push({wgt,adjNode});
                }
            }
            
        }
        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

