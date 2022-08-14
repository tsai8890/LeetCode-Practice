#include <vector>
using namespace std;

#define TRUE 1
#define FALSE -1
#define NOT_TRIED -2

/*
    Title: 416. Partition Equal Subset Sum
    Time Complexity: O(|nums| x Sumof(nums) / 2) ~= 2x10^6
    Space Complexity: O(|nums| x Sumof(nums) / 2) ~= 2x10^6 - extra space

    Algorithm: 
        1. Dynamic Programming (Top-Down)
        
    Note:
        1.  可以先把問題轉成 「找到一個subset使得其和為nums總和的一半」，如此一來，就變成
            0/1 knapsack problem，是一個典型的 DP 題目
        
            如果使用 brutal force，需要 O(2^|nums|) - time 來找出所有可能的 subset，
            但是如果使用 DP，則只需要 O(n x amount) = O(|nums| x Sumof(nums) / 2) - time

            在這題 n <= 200, nums[i] <= 100，
            所以 amount <= 200 x 100 / 2 = 10000
            O(n x amount) 大約為 2 x 10^6

        2.  Dynamic Programming (Top-Down):
            dp[n][target]: 可以使用nums[0]..nums[n]，是否能組成總和為target的subset

            #define TRUE 1
            #define FALSE -1
            #define NOT_TRIED -2

            bool helper(n, target) {
                i.  Base Case:
                    if n <= -1 or target <= 0:
                        return (target == 0)
                
                ii. Check if in dp array:
                    if dp[n][target] != NOT_TRIED:
                        return (dp[n][target] == TRUE)
                
                iii. Otherwise
                    result = helper(n-1, target-nums[n]) || helper(n-1, target)
                    dp[n][target] = result ? TRUE : FALSE
                    return result
            }

        3.  Total Time Complexity = O(|nums| x Sumof(nums) / 2)
            Total Space Complexity = O(|nums| x Sumof(nums) / 2)

    Date: 06/24/2022 13:48															    			
    Time: 47 ms  -- beat 92.97%
    Memory: 75.2 MB  -- beat 29.37%
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
            vector<vector<int>> dp(n, vector<int>((sum/2)+1, NOT_TRIED));
            return helper(n-1, sum / 2, nums, dp);
        }
    }
    
    bool helper(int n, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (n == -1 || target <= 0) {
            return (target == 0); 
        }
        else if (dp[n][target] != NOT_TRIED) {
            return (dp[n][target] == TRUE);
        }
        else {
            bool result = helper(n-1, target-nums[n], nums, dp) || helper(n-1, target, nums, dp);
            dp[n][target] = (result) ? TRUE : FALSE;
            return result;
        }
    }
};