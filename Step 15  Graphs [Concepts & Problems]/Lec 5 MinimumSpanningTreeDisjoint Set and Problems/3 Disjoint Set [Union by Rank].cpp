//todo: do dry run on copy[must]
//! tc: O(4 aplpha) ~ O(constant)
// it has both union by rank and union by size


// class of Disjoint Set
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