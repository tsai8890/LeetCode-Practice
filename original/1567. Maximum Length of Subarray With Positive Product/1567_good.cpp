#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 1567. Maximum Length of Subarray With Positive Product
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
        1. Dynamic Programming        
    
    Note:
        1. 通常DP都只會用到前一格或是前兩格，所以可以利用這點來節省空間。
           這個解法即是只記前一格。

    Date: 01/27/2022 11:44			
    Time: 108 ms  -- beat 78.12%
    Memory: 57.9 MB  -- beat 76.57%
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLen = 0;
        int max_pos = 0, max_neg = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                max_pos = max_pos + 1;
                max_neg = (max_neg != 0) ? max_neg + 1 : 0;
            }
            else if (nums[i] < 0) {
                int tmp = max_pos;
                max_pos = (max_neg != 0) ? max_neg + 1 : 0;
                max_neg = tmp + 1;
            }
            else {
                max_pos = 0;
                max_neg = 0;
            }
            
            maxLen = max(max_pos, maxLen);
        }
        return maxLen;
    }
};