#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp = {0, 0};
        for (int i = 2; i <= n; i ++) {
            dp.push_back(min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]));         
        }
        return dp[n];
    }
};