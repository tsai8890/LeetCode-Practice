#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        if (i > 0 && grid[i-1][j] == '1' && !visited[i-1][j]) {
            dfs(grid, visited, i-1, j);
        }
        if (i < grid.size()-1 && grid[i+1][j] == '1' && !visited[i+1][j]) {
            dfs(grid, visited, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == '1' && !visited[i][j-1]) {
            dfs(grid, visited, i, j-1);
        }
        if (j < grid.front().size()-1 && grid[i][j+1] == '1' && !visited[i][j+1]) {
            dfs(grid, visited, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int total = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    total += 1;
                }
            }
        }
        return total;
    }
};