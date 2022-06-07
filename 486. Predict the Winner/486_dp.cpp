#include <vector>
using namespace std;

#define hash_map vector<vector<int>>

/*
    Title: 486. Predict the Winner
    Time Complexity: O(4 x n^2)
    Space Complexity: O(2 x n^2)-extra space

    Algorithm: 
        1. Minimax Search (Game Tree)
        2. Dynamic Programming (Top-Down)
        
    Note:
        1.  典型的 Game Tree 應用，使用 Minimax Search 就可以解決了

            Minimax Search Algorithm: 
            https://mropengate.blogspot.com/2015/04/ai-ch4-minimax-alpha-beta-pruning.html
        
            max_agent:  給定一個 [left, right] 猜測區間，
                        討論拿左邊 / 拿右邊的 score 最大，並遞回給 min_agent

            min_agent:  給定一個 [left, right] 猜測區間，
                        討論拿左邊 / 拿右邊的 score 最小，並遞回給 max_agent

            Hint:   因為是 Zero-Sum Game，所以 min_agent 只需要最小化 max_agent 的分數，
                    就等同於最大化自己的分數
        
        2.  可以發現 總共只有 2 x n x n = 2 x n^2 個子問題而已
            因此可以搭配 memorization，使用 top-down DP，讓時間
            複雜度降至 O(n^2)，只是需要付出一點空間的代價

        3.  時間複雜度是 O(4 x n^2)。
            # subproblems = 2 x n^2
            # cost each subproblem = 2
            total time complexity = 4 x n^2

            空間複雜度是 O(2 x n^2)，等於子問題個數。

    Date: 06/08/2022 00:46																			    			
    Time: 0 ms  -- beat 100.00%
    Memory: 7.8 MB  -- beat 25.00%
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = 0;
        for (auto num: nums) {
            total_score += num;
        }
        
        hash_map min_dp(n, vector<int>(n, -1));
        hash_map max_dp(n, vector<int>(n, -1));
        
        int max_score = max_agent(nums, 0, n-1, min_dp, max_dp);
        return (max_score >= total_score - max_score);
    }
    
    int max_agent(vector<int>& nums, int left, int right, hash_map& min_dp, hash_map& max_dp) {
        if (left == right) {
            return nums[left];
        }
        else {
            if (max_dp[left][right] == -1) {
                max_dp[left][right] = max(nums[left] + min_agent(nums, left+1, right, min_dp, max_dp), 
                                          nums[right] + min_agent(nums, left, right-1, min_dp, max_dp));
            }
            return max_dp[left][right];
        }
    }
    
    int min_agent(vector<int>& nums, int left, int right, hash_map& min_dp, hash_map& max_dp) {
        if (left == right) {
            return 0;
        }
        else {
            if (min_dp[left][right] == -1) {
                min_dp[left][right] = min(max_agent(nums, left+1, right, min_dp, max_dp), 
                                          max_agent(nums, left, right-1, min_dp, max_dp));
            }
            return min_dp[left][right];
        }
    }
};