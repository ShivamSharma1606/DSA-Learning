//do it again
//graph question dijkstars

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minobs(m, vector<int>(n,INT_MAX));

        //starting point
        minobs[0][0] = grid[0][0];
        //creating the min-heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({minobs[0][0], 0, 0});
        // Directions for movement: right, left, down, up
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()){
            vector<int> current = pq.top();
            pq.pop();
            int obstacles = current[0];
            int row = current[1];
            int col = current[2];

            //if we reached the last column
            if(row == m-1 && col ==  n - 1){
                return obstacles;
            }

            for(vector<int> &dir: directions ){
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if(isValid(grid, newRow, newCol)){
                    int newObstacles = obstacles + grid[newRow][newCol];

                    if(newObstacles < minobs[newRow][newCol]){
                        minobs[newRow][newCol] = newObstacles;
                        pq.push({newObstacles, newRow, newCol});
                    }
                }
            }
        }

        return minobs[m - 1][n - 1];
    }

    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};