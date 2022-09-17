#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int& n, int& m, int i, int j) {
        grid[i][j] = 0;
        if (i > 0 && grid[i-1][j] == '1') {
            dfs(grid, n, m, i-1, j);
        }
        if (i < n-1 && grid[i+1][j] == '1') {
            dfs(grid, n, m, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == '1') {
            dfs(grid, n, m, i, j-1);
        }
        if (j < m-1 && grid[i][j+1] == '1') {
            dfs(grid, n, m, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int total = 0;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '1') {
                    dfs(grid, n, m, i, j);
                    total ++;
                }
            }
        }
        return total;
    }
};