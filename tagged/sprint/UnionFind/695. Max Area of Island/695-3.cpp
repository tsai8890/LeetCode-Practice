#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int max_area = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, n, m, i, j));
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, int& n, int& m, int i, int j) {
        grid[i][j] = 0;
        int totalArea = 1;
        if (i > 0 && grid[i-1][j] == 1) {
            totalArea += dfs(grid, n, m, i-1, j);
        }
        if (i <= n-2 && grid[i+1][j] == 1) {
            totalArea += dfs(grid, n, m, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == 1) {
            totalArea += dfs(grid, n, m, i, j-1);
        }
        if (j <= m-2 && grid[i][j+1] == 1) {
            totalArea += dfs(grid, n, m, i, j+1);
        }
        return totalArea;
    }
};