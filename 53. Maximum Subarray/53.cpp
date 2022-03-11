#include <algorithm>
#include <vector>
using namespace std;

/*
    Title: 53. Maximum Subarray
    Time Complexity: O(n)
    Space Complexity: O(1)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. 經典題

    Date: 01/31/2022 13:15						
    Time: 159 ms  -- beat 36.94%
    Memory: 67.8 MB  -- beat 11.56%
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxlast = nums[0], maxSum = nums[0];
        int n = nums.size();
        
        for (int i = 1; i < n; i ++) {
            maxlast = max(maxlast+nums[i], nums[i]);
            maxSum = max(maxSum, maxlast);
        }
        return maxSum;
    }
};