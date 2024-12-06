// do this question later this same question for the components of the graph
//TODO: https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTabValue=PROBLEM
//! SC:3(N) and tc: o(n)  + (2*edges)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    // recursive function
    void dfs(int node, vector<vector<int>> &adj, vector<int> &resultdfs, vector<int> &visited)
    {

        visited[node] = 1;
        resultdfs.push_back(node);

        for (auto &it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, adj, resultdfs, visited);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        vector<int> resultdfs;
        int n = adj.size();
        vector<int> visited(n, 0);
        int start = 0;
        dfs(start, adj, resultdfs, visited);
        return resultdfs;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends