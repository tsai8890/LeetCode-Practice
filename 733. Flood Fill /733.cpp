#include <vector>
using namespace std;

class Solution {
    /*
        Title: 733. Flood Fill
        Time Complexity: O(mxn)
        Algorithm: 
            1. DFS

        Date: 12/10/2021 17:06	
        Time: 4ms  -- beat 97.69%
        Memory: 14 MB  -- beat 80.52%
    */
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        vector<vector<int>> res = image;
        if (image[sr][sc] != newColor) {
            dfs(res, sr, sc, image[sr][sc], newColor, m, n);
        }
        return res;
    }
    void dfs(vector<vector<int>>& res, int sr, int sc, int tar_color, int new_color, int m, int n) {
        res[sr][sc] = new_color;
        int dir[4][2] = {{0, 1},
                         {-1, 0},
                         {0, -1},
                         {1, 0}};
        
        for (int i = 0; i < 4; i ++) {
            int new_r = sr + dir[i][0];
            int new_c = sc + dir[i][1];
            
            if (0 <= new_r && new_r < m) {
                if (0 <= new_c && new_c < n) {
                    if (res[new_r][new_c] == tar_color) {
                        dfs(res, new_r, new_c, tar_color, new_color, m, n);
                    }
                }
            }
        }
    }
};