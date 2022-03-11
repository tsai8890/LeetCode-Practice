#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 221. Maximal Square
    Time Complexity:
        1. O(MxN)

    Algorithm: 
        1. Dynamic Programming
            i.  dp[i][j]: 以 (i,j)為最右下角的正方形的最大邊長
            
            ii. 
                if (i && j)  // Not on the edge
                    if matrix[i][j] == 1
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    else
                        dp[i][j] = 0
                else
                    dp[i][j] = matrix[i][j]

    Date: 12/16/2021 22:00					
    Time: 28ms  -- beat 42.59%
    Memory: 11.9 MB  -- beat 27.35%
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int max_side = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i && j && matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                } 
                else {
                    dp[i][j] = (matrix[i][j] == '1') ? 1 : 0;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};