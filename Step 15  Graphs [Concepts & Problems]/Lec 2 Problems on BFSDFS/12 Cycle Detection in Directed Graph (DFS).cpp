// todo : check this question also of leetcode https://leetcode.com/problems/course-schedule-ii/
// todo : please check bfs solution also https://leetcode.com/problems/course-schedule-ii/solutions/59316/c-bfs-and-dfs
//! tc: same as dfs and sc: same as dfs + 2(n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool dfs(int node,vector<int> &visited, vector<int> &pvisited, vector<vector<int>> &adj ){

        visited[node]=1;
        pvisited[node]=1;

        for(auto it: adj[node]){
            if(!visited[it]){
                if(dfs(it, visited, pvisited, adj)==true){
                    return true;
                }
            }
            // if node is previouly visited and have on same path
            else if(visited[it]==pvisited[it]){
                return true;
            }
        }

        pvisited[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        //we can also do it with single array visited but for simplicity we do with do 
        vector<int> visited(V,0);
        vector<int> pvisited(V,0); //path visited

        for(int i=0 ; i < V ; i++){
            if(!visited[i]){
                if(dfs(i, visited, pvisited, adj) == true){
                    return true;
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends