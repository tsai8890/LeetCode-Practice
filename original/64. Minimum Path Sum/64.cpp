#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 64. Minimum Path Sum
    Time Complexity: O(mxn)
    Space Complexity: O(mxn)
        - 如果只記兩列，可以到O(n)

    Algorithm: 
        1. Dynamic Programming

    Date: 02/06/2022 21:54			
    Time: 4 ms  -- beat 98.85%
    Memory: 10.1 MB  -- beat 42.74%
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        int prev;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != 0 || j != 0) {
                    prev = INT_MAX;
                    if (i != 0) {
                        prev = min(prev, dp[i-1][j]);
                    }
                    if (j != 0) {
                        prev = min(prev, dp[i][j-1]);
                    }
                    dp[i][j] = grid[i][j] + prev;
                }
            }
        }
        return dp.back().back();
    }
};