//todo : must must dry run because of dfs take eg from gfg or striver video
//!tc: n*m  *log(m)[of set] + (n*m*4)[of dfs] and sc:   2(n*m)

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private: 
    //rowB: base row and colB: base column
    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>> &visited,vector<pair<int,int>> &coordinate, int rowB, int colB){
        
        visited[row][col]=1;
        coordinate.push_back({row-rowB, col-colB});
        
        int n=grid.size();
        int m=grid[0].size();
        
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        
        //finding the neighbour and perform the dfs on it
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow, ncol, grid, visited, coordinate, rowB, colB);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        //visited vector
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //set to store distict island(distinct base coordinate)
        //store the base coordinate of island
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m ;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> coordinate;
                    dfs(i,j, grid, visited,coordinate, i,j); 
                    st.insert(coordinate);
                }
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends