#include<bits/stdc++.h>
using namespace std;
//! tc: ⅀ of degree + o(n) => 0(n+ 2*total no of edges) + o(n)  and sc: o(n) 
bool find(int node, int parent,vector<vector<int>>& adj,vector<int> & visited  ){

    visited[node]=1;

    for(auto it: adj[node]){
        if(!visited[it]){
            if(find(it, node, adj, visited)==true){
                return true;
            }
        }
        //don't find the node and it is not equal to its parent
        else if (it!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n +1 , 0);
    
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
        
    // using for beacause if the graph have components
    for(int i=1;i<=n;i++){
        
        if(!visited[i]){
            if(find(i,-1, adj, visited)){
                return "Yes";
            }
        }
    }
    return "No";
    
}
