#include <vector>
#include <climits>
using namespace std;

/*
    Title: 256. Paint House
    Time Complexity: O(9xn)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1. 典型的 bottom-up DP 題目

        2. Dynamic Programming:
            color = ['red', 'blue', 'green']
            dp[i][j]: 第 i 個房子使用 color[j]，且把house[0..i]都漆完的最小 cost

            DP Transition
                dp[i][j] = costs[i][j],  if i == 0
                dp[i][j] = costs[i][j] + min(dp[i-1][k] for k in [0..2] if k != j), otherwise
        
        3. 因為這題的 DP 只會使用到 O(2 rows x 3 columns) - space，
           所以可以只用 3x2 的 vector 來儲存資訊，並利用 vectorA.swap(vectorB) 
           來節省交換的時間 (O(1)-time)。

           因此這題的空間複雜度可以達到 O(1)-extra space
        
    Date: 06/01/2022 19:31														    			
    Time: 0 ms  -- beat 100.00%
    Memory: 9.7 MB  -- beat 58.69%
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (i == 0) {
                    dp[1][j] = costs[i][j];
                }
                else {
                    int last_min = INT_MAX;
                    for (int k = 0; k < 3; k ++) {
                        if (k != j) {
                            last_min = min(last_min, dp[0][k]);
                        }
                    }
                    dp[1][j] = costs[i][j] + last_min;
                }
            }
            dp[0].swap(dp[1]);
        }
        
        int min_cost = INT_MAX;
        for (int i = 0; i < 3; i ++) {
            min_cost = min(min_cost, dp[0][i]);
        }
        return min_cost;
    }
};