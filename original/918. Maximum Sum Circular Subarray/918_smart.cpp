#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 918. Maximum Sum Circular Subarray
    Time Complexity: O(n)
    Space Complexity: O(1)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. 核心思想一樣，只是寫得更簡潔一點。
        2. 如果minSum == total_sum，代表所有two-interval的subarray的sum都是負的。
           這時可以分兩個case討論
            i.  若nums裡面至少有一個正的，則maxSum一定會找出來，而且比所有two-interval的subarray大
                ，因為所有two-interval subarray的sum都是負的。
            
            ii. 若nums裡面全部都是負的，則maxSum會找出最大的那個元素，也一定比two-interval的subarray大，
                因為所有two-interval subarray都至少包含兩個元素(全都是負的)。
            
           所以，若minSum == total_sum，直接回傳masSum即可
           反之，若minSum != total_sum，則回傳max(total_sum - minSum, maxSum)
           
    Date: 01/31/2022 15:36						
    Time: 76 ms  -- beat 53.97%
    Memory: 39.9 MB  -- beat 32.46%
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxlast = nums[0], maxSum = nums[0];
        int minlast = nums[0], minSum = nums[0];
        int total_sum = nums[0];
        
        for (int i = 1; i < n; i ++) {
            maxlast = max(maxlast+nums[i], nums[i]);
            minSum = min(minSum, minlast);
            minlast = min(minlast+nums[i], nums[i]);
            maxSum = max(maxSum, maxlast);
            total_sum += nums[i];
        }
        
        if (total_sum == minSum)
            return maxSum;
        else
            return max(maxSum, total_sum - minSum);
    }
};