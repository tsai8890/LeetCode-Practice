# define WHITE 0
# define GRAY 1
# define BLACK 2

#include <vector>
using namespace std;

class Solution {
    /*
        Title: 695. Max Area of Island
        Time Complexity: O(mxn)
        Algorithm: 
            1. DFS

        Date: 12/14/2021 11:10	
        Time: 24ms  -- beat 39.50%
        Memory: 38.5 MB  -- beat 31.00%
    */
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> color(50, vector<int>(50, WHITE));
        
        int max_area = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (color[i][j] == WHITE && grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, color, i, j, m, n));
                }
            }
        }
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& color, int sr, int sc, int m, int n) {
        int area = 1;
        color[sr][sc] = GRAY;
        
        int dir[4][2] = {
             {0, 1},
             {-1, 0},
             {0, -1},
             {1, 0}
        };
        
        int new_r;
        int new_c;
        for (int i = 0; i < 4; i ++) {
            new_r = sr + dir[i][0];
            new_c = sc + dir[i][1];
            
            if (0 <= new_r && new_r < m) {
                if (0 <= new_c && new_c < n) {
                    if (color[new_r][new_c] == WHITE && grid[new_r][new_c] == 1) {
                        area += dfs(grid, color, new_r, new_c, m, n);
                    }
                }
            }
        }
        
        return area;
    }
};