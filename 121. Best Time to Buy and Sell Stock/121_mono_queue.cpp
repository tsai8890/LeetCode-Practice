#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 121. Best Time to Buy and Sell Stock
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
        1. Monotonic queue      
    
    Note:
        1. 這題是典型的monotonic queue題型，但是因為queue裡面只會有一個元素，
           所以直接用lowest這個變數來儲存。
        
        2. 如果新的元素比lowest還小，代表lowest永遠不可能再被當成買入點，所以
           將lowest替換成新的元素;

           如果新的元素大於等於lowest，代表這是一個profit大於等於零的transaction，
           因此計算一次profit，並用max_profit儲存目前最大收益。並且，新的元素
           也不可能被當成買入點(因為lowest比它低)，所以lowest不用動。

    Date: 01/27/2022 17:24			
    Time: 120 ms  -- beat 69.63%
    Memory: 93.2 MB  -- beat 90.22%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] < lowest) {
                lowest = prices[i];
            }
            else {
                if (prices[i] - lowest > max_profit) {
                    max_profit = prices[i] - lowest;
                }
            }
        }
        return max_profit;
    }
};