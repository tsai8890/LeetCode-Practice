#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int dp[n][m];
        
        int longest = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (nums1[i] == nums2[j]) ? 1 : 0;
                }
                else if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }    
                else {
                    dp[i][j] = 0;
                }
                
                longest = max(longest, dp[i][j]);
            }
        }
        return longest;
    }
};