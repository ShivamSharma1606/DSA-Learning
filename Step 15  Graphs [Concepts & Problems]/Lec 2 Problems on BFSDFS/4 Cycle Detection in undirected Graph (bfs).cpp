//! tc: ⅀ of degree = 0( 2*total no of edges) + o(n)  and sc: o(n)
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool find(int node,vector<vector<int>>& adj,vector<int>& visited ){
        visited[node]=1;
        
        //{node,parent}
        queue<pair<int,int>> q;
        //Intially their is no parent of starting node
        q.push({node,-1});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int vertix = it.first;
            int parent = it.second;
            
            for(auto adjacent: adj[vertix]){
                
                if(!visited[adjacent]){
                    visited[adjacent]=1;
                    q.push({adjacent,vertix});
                }
                //hence loop is formed
                else if(adjacent != parent){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visited(n,0);
        
        // using for beacause if the graph have components
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
                if(find(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends