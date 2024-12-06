//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      void bfs(int row, int col, vector<vector<int>>& visited,
                 vector<vector<char>>& grid) {
    
            int n = grid.size();
            int m = grid[0].size();
            visited[row][col] = 1;
            // storing the row and column
            queue<pair<int, int>> q;
            q.push({row, col});
    
            //{up,left,down,right,dia left-up, dia right-up, dia left-down, dia right-down}
            int srow[8] = {-1, 0, 1, 0,-1,-1,1,1}; // surronding rows
            int scol[8] = {0, -1, 0, 1,-1,1,-1,1}; // surronding columns
    
            while (!q.empty()) {
                auto island = q.front();
                q.pop();
                int r = island.first;
                int c = island.second;
    
                for (int i = 0; i < 8; i++) {
                    int row = r + srow[i];
                    int col = c + scol[i];
    
                    if (row >= 0 && col >= 0 && row < n && col < m &&
                        !visited[row][col] && grid[row][col] == '1') {
                        q.push({row, col});
                        visited[row][col] = 1;
                    }
                }
            }
        }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Initally all node are not visted
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0; // count the number of distict island

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, visited, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends