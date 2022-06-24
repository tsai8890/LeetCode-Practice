#include <vector>
using namespace std;

/*
    Title: 416. Partition Equal Subset Sum
    Time Complexity: O(|nums| x Sumof(nums) / 2) ~= 2x10^6
    Space Complexity: O(|nums| x Sumof(nums) / 2) ~= 2x10^6 - extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1.  可以先把問題轉成 「找到一個subset使得其和為nums總和的一半」，如此一來，就變成
            0/1 knapsack problem，是一個典型的 DP 題目
        
            如果使用 brutal force，需要 O(2^|nums|) - time 來找出所有可能的 subset，
            但是如果使用 DP，則只需要 O(n x amount) = O(|nums| x Sumof(nums) / 2) - time

            在這題 n <= 200, nums[i] <= 100，
            所以 amount <= 200 x 100 / 2 = 10000
            O(n x amount) 大約為 2 x 10^6

        2.  Dynamic Programming (Bottom-Up):
            dp[n][target]: 可以使用nums[0]..nums[n]，是否能組成總和為target的subset

            DP Transition:
                i.  Base Case: 
                        if j == 0: dp[i][j] = true
                
                ii. Transition:
                        if i != 0:
                            if nums[i] <= j:
                                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
                            else:
                                dp[i][j] = dp[i-1][j]
                        else:
                            dp[i][j] = (nums[i] == j)

        3.  Total Time Complexity = O(|nums| x Sumof(nums) / 2)
            Total Space Complexity = O(|nums| x Sumof(nums) / 2)

        4.  使用 bottom-up DP 會比 top-down DP 慢很多，因為 bottom-up 會真的把整個
            二維 dp array 的每一格都計算一遍，而 top-down 並不會算到每一格，只會算需要算的
            那些位置。 因此，top-down DP 在這題比較有利。

    Date: 06/24/2022 14:37															    			
    Time: 368 ms  -- beat 35.62%
    Memory: 11.8 MB  -- beat 62.41%
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        else {
            vector<vector<bool>> dp(n, vector<bool>((sum/2)+1));
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j <= sum / 2; j ++) {
                    if (j == 0) {
                        dp[i][j] = true;
                    }
                    else {
                        if (i == 0) {
                            dp[i][j] = (nums[i] == j);
                        }
                        else {
                            if (nums[i] <= j) {
                                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                            }
                            else {
                                dp[i][j] = dp[i-1][j];
                            }
                        }
                    }
                }
            }
            return dp[n-1][sum/2];
        }
    }
};