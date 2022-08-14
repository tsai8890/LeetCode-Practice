#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    /*
        Title: 740. Delete and Earn
        Time Complexity: O(NlogN)
        Algorithm: 
            1. Dynamic Programming
                i.   dp[0] = nums_table[0] * nums_count[nums_table[0]]
                
                ii.  if nums_table[0] + 1 == nums_table[1],
                        dp[1] = max(dp[0], nums_table[1] * nums_count[nums_table[1])
                     otherwise,
                        dp[i] = dp[0] + nums_table[1] * nums_count[nums_table[1]

                iii. if nums_table[i-1] + 1 == nums_table[i],
                        dp[i] = max(dp[i-1], nums_table[i] * nums_count[nums_table[i] + dp[i-2])
                     otherwise,
                        dp[i] = dp[i-1] + nums_table[i] * nums_count[nums_table[i]
        Note:
            1. Copy 'nums' to 'tmp' and sort 'tmp'
            2. Use 'nums_table' to record distinct numbers in 'tmp'.
            3. Use 'nums_count' to record each distinct number's occuring times.

        Date: 12/09/2021 22:25				
        Time: 4ms  -- beat 93.15%
        Memory: 11.9 MB  -- beat 24.63%
    */
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> nums_table;
        vector<int> nums_count(10000+5, 0);
        
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < tmp.size();i ++) {
            if (nums_table.size() == 0) {
                nums_table.push_back(tmp[i]);
            } else if (nums_table[nums_table.size()-1] != tmp[i]) {
                nums_table.push_back(tmp[i]);
            }
            nums_count[tmp[i]] += 1;
        }
        
        if (nums_table.size() == 1) {
            return nums_table[0] * nums_count[nums_table[0]];
        }
        
        vector<int> dp(nums_table.size(), 0);
        dp[0] = nums_table[0] * nums_count[nums_table[0]];
        if (nums_table[0] + 1 == nums_table[1]) {
            dp[1] = max(dp[0], nums_table[1] * nums_count[nums_table[1]]);
        } else {
            dp[1] = dp[0] + nums_table[1] * nums_count[nums_table[1]];
        }
        
        for (int i = 2; i < nums_table.size(); i ++) {
            int cur = nums_table[i];
            int bef = nums_table[i-1];
            if (bef + 1 == cur) {
                dp[i] = max(cur * nums_count[cur] + dp[i-2], dp[i-1]);
            } else {
                dp[i] = cur * nums_count[cur] + dp[i-1];
            }
        }
        return dp[nums_table.size() - 1];
    }
};