#include <vector>
using namespace std;

class Solution {
public:
    pair<bool, int> dfs(vector<vector<int>>& grid, int& n, int& m, int i, int j) {
        grid[i][j] = 0;
        bool valid = !(i == 0 || i == n-1 || j == 0 || j == m-1);
        int count = 1;
        
        pair<bool, int> res;
        if (i > 0 && grid[i-1][j] == 1) {
            res = dfs(grid, n, m, i-1, j);
            valid = valid && res.first;
            count += res.second;
        } 
        if (i <= n-2 && grid[i+1][j] == 1) {
            res = dfs(grid, n, m, i+1, j);
            valid = valid && res.first;
            count += res.second;
        }
        if (j > 0 && grid[i][j-1] == 1) {
            res = dfs(grid, n, m, i, j-1);
            valid = valid && res.first;
            count += res.second;
        }
        if (j <= m-2 && grid[i][j+1] == 1) {
            res = dfs(grid, n, m, i, j+1);
            valid = valid && res.first;
            count += res.second;
        }
        return make_pair(valid, count);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int total = 0;
        int n = grid.size();
        int m = grid.front().size();
        pair<bool, int> curRes;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    curRes = dfs(grid, n, m, i, j);
                    if (curRes.first) {
                        total += curRes.second;
                    }
                }
            }
        }
        return total;
    }
};