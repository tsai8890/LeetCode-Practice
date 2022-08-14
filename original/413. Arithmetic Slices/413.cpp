#include <vector>
using namespace std;

/*
    Title: 413. Arithmetic Slices
    Time Complexity: O(n)
    Space Complexity: O(n)
        - 如果只記前一個，可以到O(1)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. dp[i]: 以nums[i]為結尾的arithmetic array個數
            轉移方程：
                if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) 
                    dp[i] = dp[i-1] + 1  
                else
                    dp[i] = 0

    Date: 01/30/2022 22:58						
    Time: 0 ms  -- beat 100.00%
    Memory: 7.4 MB  -- beat 52.41%
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        
        vector<int> dp = {0, 0};
        int total_count = 0;

        for (int i = 2; i < nums.size(); i ++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp.push_back(dp[i-1] + 1);
            }
            else {
                dp.push_back(0);
            }
            total_count += dp.back();
        }
        return total_count;
    }
};