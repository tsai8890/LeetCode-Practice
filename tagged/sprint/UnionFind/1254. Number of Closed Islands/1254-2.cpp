#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int& n, int& m, int i, int j) {
        grid[i][j] = 1;
        bool res = !(i == 0 || i == n-1 || j == 0 || j == m-1); 
        if (i > 0 && grid[i-1][j] == 0) {
            res = dfs(grid, n, m, i-1, j) && res;
        }
        if (i <= n-2 && grid[i+1][j] == 0) {
            res = dfs(grid, n, m, i+1, j) && res;
        }
        if (j > 0 && grid[i][j-1] == 0) {
            res = dfs(grid, n, m, i, j-1) && res;
        }
        if (j <= m-2 && grid[i][j+1] == 0) {
            res = dfs(grid, n, m, i, j+1) && res;
        }
        return res;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int total = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, n, m, i, j)) {
                        total += 1;
                    }
                }
            }
        }
        return total;
    }
};