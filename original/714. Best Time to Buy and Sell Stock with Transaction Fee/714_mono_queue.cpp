#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 714. Best Time to Buy and Sell Stock with Transaction Fee
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
        1. Monotonic Queue
    
    Note:
        1. 做法和LeetCode 121的概念一樣，只是在處理更改lowest時有更多細節要處理。
        2. 簡而言之，是一個常數比DP小的做法，但是實作上很繁瑣且容易出錯，如果可以，
           使用DP來實作是比較理想的。

    Date: 01/28/2022 00:33					
    Time: 92 ms  -- beat 83.69%
    Memory: 55.1 MB  -- beat 56.70%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int total_profit = 0;
        int lowest = prices[0], highest = -1;
        
        for (int i = 1; i < prices.size(); i ++) {
            if (highest == -1) {
                if (prices[i] > lowest) {
                    highest = prices[i];
                }
                if (prices[i] < lowest) {
                    lowest = prices[i];
                }
            }
            else {
                if (prices[i] >= highest) {
                    highest = prices[i];
                }
                else {
                    if (highest - lowest >= fee) {
                        if (highest - prices[i] > fee) {
                            total_profit += highest - lowest - fee;
                            lowest = prices[i];
                            highest = -1;
                        }
                    }
                    else {
                        if (prices[i] < lowest) {
                            lowest = prices[i];
                            highest = -1;
                        }
                    }
                }
            }
        }
        
        if (highest != -1 && highest - lowest > fee)
            total_profit += highest - lowest - fee;
        return total_profit;
    }
};