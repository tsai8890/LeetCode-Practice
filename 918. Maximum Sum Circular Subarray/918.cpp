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
        1.  和LeetCode 53. Maximum Subarray很像，只是需要多考慮circular的部分。
            可以先把所有subarray分成兩種，
                i.  one-interval，即start < end
                    - 找法就是LeetCode 53. 的做法

                ii. two-interval，即start > end，有利用到circular的部分
                    - 找法是找出在nums[1..n-2]中的minimum subarray，
                      只要找到minimum subarray，就可以保證nums array扣除掉
                      minimum subarray的部分會最大，進而求得最大的two-interval
                      subarray。
                    
                    - 關鍵： 
                        minimum subarray只需要在nums[1..n-2]中找，不需要
                        去看nums[0]跟nums[n-1]，因為所有two-interval的subarray
                        沒包含到的部分一定在nums[1..n-2]之間。

            接著比較i.跟ii.求得的subarray，就可以得到最後的答案。           
           
    Date: 01/31/2022 14:56						
    Time: 48 ms  -- beat 98.73%
    Memory: 39.8 MB  -- beat 71.30%
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxlast = nums[0], maxSum = nums[0];
        for (int i = 1; i < n; i ++) {
            maxlast = max(maxlast+nums[i], nums[i]);
            maxSum = max(maxSum, maxlast);
        }
        
        if (n < 3) {
            return maxSum;
        }
        else {
            int total_sum = 0;
            for (int i = 0; i < n; i ++) {
                total_sum += nums[i];
            }

            int minlast = nums[1], minSum = nums[1];
            for (int i = 2; i < n-1; i ++) {
                minlast = min(minlast+nums[i], nums[i]);
                minSum = min(minSum, minlast);
            }
            return max(total_sum - minSum, maxSum);
        }
    }
};