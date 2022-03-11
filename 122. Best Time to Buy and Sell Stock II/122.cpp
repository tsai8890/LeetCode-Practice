#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 122. Best Time to Buy and Sell Stock II
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
                cash[i] = max(cash[i-1], hold[i-1] + prices[i])

        2. 和LeetCode 714.一模一樣，把fee去掉就行了

    Date: 01/28/2022 17:05			
    Time: 4 ms  -- beat 92.07%
    Memory: 13.3 MB  -- beat 5.45%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hold(prices.size());
        vector<int> cash(prices.size());
        hold[0] = -prices[0];
        cash[0] = 0;
        
        for (int i = 1; i < prices.size(); i ++) {
            hold[i] = max(hold[i-1], cash[i-1] - prices[i]);
            cash[i] = max(cash[i-1], hold[i-1] + prices[i]);
        }
        return cash.back();
    }
};