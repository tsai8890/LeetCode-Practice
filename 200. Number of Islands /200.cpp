#include <vector>
using namespace std;

class Solution {
    /*
        Title: 200. Number of Islands
        Time Complexity: O(N)
        Algorithm: 
            1. DFS

        Date: 12/15/2021 20:41				
        Time: 36ms  -- beat 57.19%
        Memory: 12.3 MB  -- beat 83.07%
    */
public:
    vector<vector<int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
     
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    count += 1;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col, int nrows, int ncols) {
        grid[row][col] = '0';
        int new_r, new_c;
        
        for (int i = 0; i < 4; i ++) {
            new_r = row + dirs[i][0];
            new_c = col + dirs[i][1];
            
            if (0 <= new_r && new_r < nrows) {
                if (0 <= new_c && new_c < ncols) {
                    if (grid[new_r][new_c] == '1') {
                        dfs(grid, new_r, new_c, nrows, ncols);
                    }
                }
            }
        }
    }
};