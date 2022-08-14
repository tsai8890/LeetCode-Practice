#include <vector>
using namespace std;

/*
    Title: 486. Predict the Winner
    Time Complexity: O(2^n)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Minimax Search (Game Tree)
        
    Note:
        1.  典型的 Game Tree 應用，使用 Minimax Search 就可以解決了

            Minimax Search Algorithm: 
            https://mropengate.blogspot.com/2015/04/ai-ch4-minimax-alpha-beta-pruning.html
        
            max_agent:  給定一個 [left, right] 猜測區間，
                        討論拿左邊 / 拿右邊的 score 最大，並遞迴給 min_agent

            min_agent:  給定一個 [left, right] 猜測區間，
                        討論拿左邊 / 拿右邊的 score 最小，並遞迴給 max_agent

            Hint:   因為是 Zero-Sum Game，所以 min_agent 只需要最小化 max_agent 的分數，
                    就等同於最大化自己的分數

        2.  時間複雜度是 O(2^n)，指數時間。
            空間複雜度是 O(n)，等於遞迴深度。

    Date: 06/08/2022 00:27																		    			
    Time: 125 ms  -- beat 30.99%
    Memory: 7.4 MB  -- beat 67.98%
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = 0;
        for (auto num: nums) {
            total_score += num;
        }

        int max_score = max_agent(nums, 0, n-1);
        return (max_score >= total_score - max_score);
    }
    
    int max_agent(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        else {
            return max(nums[left] + min_agent(nums, left+1, right), 
                       nums[right] + min_agent(nums, left, right-1));
        }
    }
    
    int min_agent(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }
        else {
            return min(max_agent(nums, left+1, right), max_agent(nums, left, right-1));
        }
    }
};