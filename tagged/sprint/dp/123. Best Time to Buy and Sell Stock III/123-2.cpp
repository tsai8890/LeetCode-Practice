#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // base case
        int n = prices.size();
        const int MIN = -100005;
        int buy1, sell1;
        int buy2, sell2;
        
        for (int i = 0; i < n; i ++) {
            sell2 = (i < 3) ? MIN : max(buy2+prices[i], sell2);
            buy2 = (i < 2) ? MIN : max(sell1-prices[i], buy2);
            sell1 = (i < 1) ? MIN : max(buy1+prices[i], sell1);
            buy1 = (i == 0) ? -prices[0] : max(-prices[i], buy1);
        }
        return max(0, max(sell1, sell2));
    }
};