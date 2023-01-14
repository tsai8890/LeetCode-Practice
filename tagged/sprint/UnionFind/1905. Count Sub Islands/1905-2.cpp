#include <vector>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1.front().size();
        
        int total = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid2[i][j] == 1 && check(grid1, grid2, i, j)) {
                    total += 1;
                }
            }
        }
        return total;
    }
    
    bool check(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int n = grid1.size();
        int m = grid1.front().size();
        grid2[i][j] = 0;
        
        bool res = (grid1[i][j] == 1);
        if (i > 0 && grid2[i-1][j] == 1) {
            res = check(grid1, grid2, i-1, j) && res;
        }
        if (i <= n-2 && grid2[i+1][j] == 1) {
            res = check(grid1, grid2, i+1, j) && res;
        }
        if (j > 0 && grid2[i][j-1] == 1) {
            res = check(grid1, grid2, i, j-1) && res;
        }
        if (j <= m-2 && grid2[i][j+1] == 1) {
            res = check(grid1, grid2, i, j+1) && res;
        }
        return res;
    }
};