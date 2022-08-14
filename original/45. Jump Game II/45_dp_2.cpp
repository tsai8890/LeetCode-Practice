#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 45. Jump Game II
    Time Complexity: O(n x k), where k is the maximum value of nums
    Space Complexity: O(n)
    
    Algorithm:
        1. Dynamic Programming(Purely Bottom Up)

    Note: 
        1. It's better than the original DP solution, 
           which solves the problem with O(n^2)-time.
           
    Date: 01/30/2022 21:09						
    Time: 600 ms  -- beat 15.42%
    Memory: 17.2 MB  -- beat 17.32%
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        
        for (int i = 0; i < dp.size(); i ++) {
            for (int j = i; j < dp.size() && j <= i+nums[i]; j ++) {
                dp[j] = min(dp[j], dp[i]+1);
            }    
        }
        return dp.back();
    }
};