#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    /*
        Title: 746. Min Cost Climbing Stairs
        Time Complexity: O(N)
        Note:
            1. Dynamic Programming
            2. dp[i] = min(dp[i-1], dp[i-2]) + cost[i]      
            3. result = min(dp[N-1], dp[N-2])

        Date: 12/07/2021 11:33	
        Time: 4 ms  -- beat 90.35%
        Memory: 14 MB  -- beat 9.51%
    */
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = {cost[0], cost[1]};
        for (int i = 2; i < cost.size(); i ++) {
            dp.push_back(min(dp[i-1], dp[i-2]) + cost[i]);
        }
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};