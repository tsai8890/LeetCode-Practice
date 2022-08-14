#include <vector>
using namespace std;

class Solution {
    /*
        Title: 1277. Count Square Submatrices with All Ones
        Time Complexity:
            1. O(MxN)

        Algorithm: 
            1. Dynamic Programming
                i.  dp[i][j]: 以 (i,j)為最右下角的正方形的數量
                
                ii. 
                    if (i && j)  // Not on the edge
                        if matrix[i][j] == 1
                            dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                        else
                            dp[i][j] = 0
                    else
                        dp[i][j] = matrix[i][j]

        Date: 12/16/2021 21:28					
        Time: 60ms  -- beat 82.51%
        Memory: 26.4 MB  -- beat 7.19%
    */
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int sum_squares = 0;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                if (i && j) {
                    dp[i][j] = (matrix[i][j] == 1) ? \
                                min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1 : 0;
                } else {
                    dp[i][j] = matrix[i][j];
                }
                sum_squares += dp[i][j];
            }
        }
        return sum_squares;
    }
};