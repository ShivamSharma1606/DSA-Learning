/*
1. sort the edges according to weight
2. treat each node as self components
3. if their is no common ultimate parrent then their will be a link between this node
4. if their is common ultimate parent then no updation in mstWT will be done
*/
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
   
        vector<int> parent;
        vector<int> rank ,size;
    public: 
    //making the constructor
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    //finding the ultimate parent
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void UnionByRank(int u, int v){
        //finding the ultimate parent of u an v first
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        //if parent have same then no need to update
        if(ulp_u == ulp_v)  return;
        //if rank of ulp_v is greater than ulp_u
        if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        //if both have same rank than ulp_v,ulp_u any can be parent[choice]
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};


int kruskalMST(int n, vector<vector<int>> &edges)
{
	vector<pair<int, pair<int,int>>> ed;

	for( auto it: edges)  {
		int u = it[0];
		int v = it[1];
		int wt = it[2];

		ed.push_back({wt,{u,v}});
	}

	//sort the edges based on their weight
	sort(ed.begin(), ed.end());

	DisjointSet ds(n);
	int mstWt = 0;

	for(auto it: ed){
		int wt = it.first;
		int u = it.second.first;
		int v = it.second.second;

		if(ds.findUPar(u) != ds.findUPar(v)){
			mstWt += wt;
			ds.unionBySize(u, v);
		}
	}
	
	return mstWt;
}
