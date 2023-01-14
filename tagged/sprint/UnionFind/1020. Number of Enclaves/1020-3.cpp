#include <vector>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int& n, int& m, int i, int j) {
        grid[i][j] = 0;
        int count = 1;

        if (i > 0 && grid[i-1][j] == 1) {
            count += dfs(grid, n, m, i-1, j);
        } 
        if (i <= n-2 && grid[i+1][j] == 1) {
            count += dfs(grid, n, m, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == 1) {
            count += dfs(grid, n, m, i, j-1);
        }
        if (j <= m-2 && grid[i][j+1] == 1) {
            count += dfs(grid, n, m, i, j+1);
        }
        return count;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (grid[i][j] == 1) {
                        dfs(grid, n, m, i, j);
                    }
                }
            }
        }
        
        int total = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    total += dfs(grid, n, m, i, j);
                }
            }
        }
        return total;
    }
};