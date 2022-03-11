#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 309. Best Time to Buy and Sell Stock with Cooldown
    Time Complexity: O(N)
    Space Complexity: O(N)
        - 如果只記前一格，就可以縮減到O(1)

    Algorithm:
        1. Dynamic Programming      
    
    Note:
        1. hold[i]: 第i天持股時的最大利潤
           cash[i]: 第i天不持股(且隔天可以馬上買股)時的最大利潤
           cooldown[i]: 第i天剛賣完股票時的最大利潤

            轉移方程：
                hold[i] = max(hold[i-1], cash[i-1] - prices[i]);
                cash[i] = max(cash[i-1], cooldown[i-1])
                cooldown[i] = hold[i-1] + prices[i];

        2. 類似題: LeetCode Problem 121., 714.
        
    Date: 01/28/2022 16:49					
    Time: 0 ms  -- beat 100.00%
    Memory: 11.2 MB  -- beat 50.98%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hold(prices.size());
        vector<int> cash(prices.size());
        vector<int> cooldown(prices.size());
        
        hold[0] = -prices[0];
        cash[0] = 0;
        cooldown[0] = -INT_MAX;
        
        for (int i = 1; i < prices.size(); i ++) {
            hold[i] = max(hold[i-1], cash[i-1] - prices[i]);
            cash[i] = max(cash[i-1], cooldown[i-1]);
            cooldown[i] = hold[i-1] + prices[i];
        }
        return max(cooldown[prices.size()-1], cash[prices.size()-1]);
    }
};