#include <vector>
#include <climits>
using namespace std;

/*
    Title: 256. Paint House
    Time Complexity: O(9xn)
    Space Complexity: O(3xn)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1. 典型的 bottom-up DP 題目

        2. Dynamic Programming:
            color = ['red', 'blue', 'green']
            dp[i][j]: 第 i 個房子使用 color[j]，且把house[0..i]都漆完的最小 cost

            DP Transition
                dp[i][j] = 1,  if i == 0
                dp[i][j] = costs[i][j] + min(dp[i-1][k] for k in [0..2] if k != j)
        
    Date: 06/01/2022 10:27													    			
    Time: 4 ms  -- beat 96.35%
    Memory: 10.3 MB  -- beat 18.71%
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (i == 0) {
                    dp[i][j] = costs[i][j];
                }
                else {
                    int last_min = INT_MAX;
                    for (int k = 0; k < 3; k ++) {
                        if (k != j) {
                            last_min = min(last_min, dp[i-1][k]);
                        }
                    }
                    dp[i][j] = costs[i][j] + last_min;
                }
            }
        }
        
        int min_cost = INT_MAX;
        for (int i = 0; i < 3; i ++) {
            min_cost = min(min_cost, dp[n-1][i]);
        }
        return min_cost;
    }
};