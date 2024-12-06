//! same complexity as bfs
//bipartite graph is a graph where each node have different color, and adjacent node can't have same color,the max color allowed is 2
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& color) {

        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int edge = q.front();
            q.pop();

            for (auto it : graph[edge]) {
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = !color[edge];
                }
                //same color as adjacent 
                else if (color[it] == color[edge]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //their may be two color "0" or "1" or no color "-1"
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(i, graph, color) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};