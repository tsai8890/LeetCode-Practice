#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 714. Best Time to Buy and Sell Stock with Transaction Fee
    Time Complexity: O(N)
    Space Complexity: O(N)
        - 如果只記前一格，就可以縮減到O(1)

    Algorithm:
        1. Dynamic Programming      
    
    Note:
        1. hold[i]: 第i天持股時的最大利潤
           cash[i]: 第i天不持股時的最大利潤

            轉移方程：
                hold[i] = max(hold[i-1], cash[i-1] - prices[i])
                cash[i] = max(cash[i-1], hold[i-1] + prices[i] - fee)

        2. 類似題: LeetCode Problem 121., 309.

    Date: 01/27/2022 22:53				
    Time: 96 ms  -- beat 75.58%
    Memory: 59.7 MB  -- beat 30.28%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> hold(prices.size());
        vector<int> cash(prices.size());
        hold[0] = -prices[0];
        cash[0] = 0;
        
        for (int i = 1; i < prices.size(); i ++) {
            hold[i] = max(hold[i-1], cash[i-1] - prices[i]);
            cash[i] = max(cash[i-1], hold[i-1] + prices[i] - fee);
        }
        return cash[prices.size()-1];
    }
};