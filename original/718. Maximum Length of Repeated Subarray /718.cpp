#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 718. Maximum Length of Repeated Subarray
        Time Complexity: O(NxM)
        Algorithm: 
            1. Dynamic Programming
            2. dp[i][j]: 結尾同時是nums1[i] & nums2[j]的最長subarray
            3. dp[i][j] = 0                     If nums1[i] != nums2[j]
                        = dp[i-1][j-1] + 1      Otherwise
                        
        Date: 12/02/2021 22:04
        Time: 148 ms  -- beat 90.28%
        Memory: 16.1 MB  -- beat 73.00%
    */
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int dp[n+1][m+1];
        for (int i = 0; i < n + 1; i ++) {
           dp[i][0] = 0; 
        }
        
        for (int i = 0; i < m + 1; i ++) {
            dp[0][i] = 0;
        }
        
        int res;
        for (int i = 1; i < n + 1; i ++) {
            for (int j = 1; j < m + 1; j ++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};