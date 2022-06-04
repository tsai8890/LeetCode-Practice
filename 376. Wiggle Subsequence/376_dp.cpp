#include <vector>
using namespace std;

/*
    Title: 376. Wiggle Subsequence
    Time Complexity: O(n^2)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1.  典型的 bottom-up DP 題目

        2.  Dynamic Programming:
            up[i]:   以nums[i]為結尾，且最後一個元素是 wiggle up 的最長 wiggle subsequence 的長度
            down[i]: 以nums[i]為結尾，且最後一個元素是 wiggle down 的最長 wiggle subsequence 的長度
            DP Transition
                i.      up[i] = max(down[k] for k in [0..i-1]) + 1
                ii.     down[i] = max(up[k] for k in [0..i-1]) + 1
        
        3.  時間複雜度： O(n^2)
                # subproblems = O(n)
                # cost each subproblem = O(n)
                Total Time Complexity: O(n^2)
            
            空間複雜度： O(n)

        4. 這題可以壓到 O(n)-time & O(1)-space，之後會再補上來。

    Date: 06/05/2022 00:14																    			
    Time: 23 ms  -- beat 11.27%
    Memory: 7.3 MB  -- beat 17.01%
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        
        int maxLen = 0;
        for (int i = 0; i < n; i ++) {
            int last_max = 0;
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    last_max = max(last_max, down[j]);
                }
            }
            up[i] = last_max + 1;
            
            last_max = 0;
            for (int j = 0; j < i; j ++) {
                if (nums[i] < nums[j]) {
                    last_max = max(last_max, up[j]);
                }
            }
            down[i] = last_max + 1;
            
            maxLen = max(maxLen, max(up[i], down[i]));
        }
        return maxLen;
    }
};