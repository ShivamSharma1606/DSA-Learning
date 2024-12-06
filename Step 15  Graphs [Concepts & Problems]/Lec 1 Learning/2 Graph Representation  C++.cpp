//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
       
       vector<vector<int>> adj(V);  // we know the size of main matrix but not of the submatrix
       for(auto &it:edges){
           adj[it.first].push_back(it.second);
           adj[it.second].push_back(it.first);
       }
       return adj;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        bool empty = true;
        for (int i = 0; i < V; i++) {
            if (adj[i].empty())
                continue;
            empty = false;
            break;
        }
        if (empty) {
            cout << "[]\n";
            continue;
        }
        for (int i = 0; i < V; i++) {
            set<int> st(adj[i].begin(), adj[i].end());
            cout << "[";
            auto it = st.begin();

            while (it != st.end()) {
                cout << *it;
                if (next(it) != st.end())
                    cout << " ";
                ++it;
            }
            cout << "]";
            cout << endl;
        }
    }
}
// } Driver Code Ends