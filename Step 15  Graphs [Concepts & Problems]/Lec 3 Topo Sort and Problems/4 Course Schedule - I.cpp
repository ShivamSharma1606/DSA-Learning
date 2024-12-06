// two method 
/*
1. BFS: Finding the cycle in the graph if their is a cycle then it will return false
2. TOPO SORT: Help to find the linearity in the node if schedule is NOT DAG then return false
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //converting into adj matrix
        vector<vector<int>> adj(numCourses);
        for(auto &it: prerequisites ){
            adj[it[0]].push_back(it[1]);
        }

        int n = adj.size();

        // finding the indegree of all node
        vector<int> indegree(n, 0);
        for (int i = 0; i < adj.size(); i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        // push all node have indegree zero(dag have alway aleaset one node have 0 degree)

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {

            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto it : adj[node])
            {

                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if(topo.size()==numCourses) return true;
        return false;
    }
};