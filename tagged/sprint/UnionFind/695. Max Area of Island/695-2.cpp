#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int max_area = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, visited, n, m, i, j));
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& n, int& m, int i, int j) {
        visited[i][j] = true;
        int totalArea = 1;
        if (i > 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
            totalArea += dfs(grid, visited, n, m, i-1, j);
        }
        if (i <= n-2 && grid[i+1][j] == 1 && !visited[i+1][j]) {
            totalArea += dfs(grid, visited, n, m, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
            totalArea += dfs(grid, visited, n, m, i, j-1);
        }
        if (j <= m-2 && grid[i][j+1] == 1 && !visited[i][j+1]) {
            totalArea += dfs(grid, visited, n, m, i, j+1);
        }
        return totalArea;
    }
};