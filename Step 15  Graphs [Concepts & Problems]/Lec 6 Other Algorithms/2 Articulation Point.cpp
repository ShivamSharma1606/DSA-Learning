//do problem 1 first

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visited, vector<int> &tin, vector<int> &low, vector<int> &mark, vector<int> adj[])
    {

        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0;

        for (auto it : adj[node])
        {
            // if neigbour is parent then no need to compare it's low
            if (it == parent)
                continue;
            if (!visited[it])
            {
                dfs(it, node, visited, tin, low, mark, adj);
                // finding the lowest neigbour excepth parent
                low[node] = min(low[node], low[it]);

                // node---it
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                // finding the lowest neigbour excepth parent
                low[node] = min(low[node], tin[it]);
            }
        }

        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int v, vector<int> adj[])
    {
        vector<int> visited(v, 0);
        vector<int> tin(v);
        vector<int> low(v);
        vector<int> mark(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, -1, visited, tin, low, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
