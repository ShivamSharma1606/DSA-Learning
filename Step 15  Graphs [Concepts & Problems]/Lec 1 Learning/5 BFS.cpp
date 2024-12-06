//! space complexity: 3(n) and time complexity:  o(n) + 2(Edges)
#include<bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{

    vector<int> result;
    vector<int> visited(n + 1, 0); // for checking is vertice encountered before or not
    queue<int> q;
    q.push(0);      // given starting from index 0
    visited[0] = 1; // as we insert the first element in the stack

    while (!q.empty())
    {

        int node = q.front();
        result.push_back(node);
        q.pop();

        // finding the neighbour of that node
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return result;
}