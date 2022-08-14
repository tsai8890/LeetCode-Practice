#include <vector>
using namespace std;

/*
    Title: 152. Maximum Product Subarray
    Time Complexity: 
        1. O(n)

    Algorithm:
        1. Dynamic Programming
        
    Note:
        1. 要記兩個值，一個是"以上一個元素為結尾的subarray的maximum值"，
           一個是"以上一個元素為結尾的subarray的minimum值"。

    Date: 01/04/2022 00:56										
    Time: 6 ms  -- beat 41.76%
    Memory: 13.8 MB  -- beat 6.26%
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = nums[0], cur_min = nums[0];
        int maxVal = nums[0];
        
        int tmp_cur_max;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                cur_max = max(nums[i], nums[i] * cur_max);
                cur_min = min(nums[i], nums[i] * cur_min);
            }
            else {
                tmp_cur_max = cur_max;
                cur_max = max(nums[i], nums[i] * cur_min);
                cur_min = min(nums[i], nums[i] * tmp_cur_max);
            }
            maxVal = max(maxVal, cur_max);
        }
        return maxVal;   
    }
};