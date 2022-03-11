#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 121. Best Time to Buy and Sell Stock
    Time Complexity: O(N)
    Space Complexity: O(N)
        - 如果只記前一格，就可以縮減到O(1)

    Algorithm:
        1. Dynamic Programming     
    
    Note:
        1.  hold[i]: 第i天持有股份時的最大利潤
            cash[i]: 第i天沒有持有股份時的最大利潤
           
            轉移方程：
                hold[i] = max(-prices[i], hold[i-1])
                cash[i] = max(prices[i] + hold[i-1], cash[i-1])

        2. 類似題: LeetCode Problem 714., 309.

    Date: 01/27/2022 23:25			
    Time: 172 ms  -- beat 41.02%
    Memory: 101.2 MB  -- beat 5.71%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hold(prices.size());
        vector<int> cash(prices.size());
        hold[0] = -prices[0];
        cash[0] = 0;
        
        for (int i = 1; i < prices.size(); i ++) {
            hold[i] = max(-prices[i], hold[i-1]);
            cash[i] = max(prices[i] + hold[i-1], cash[i-1]);
        }
        return cash[prices.size()-1];
    }
};