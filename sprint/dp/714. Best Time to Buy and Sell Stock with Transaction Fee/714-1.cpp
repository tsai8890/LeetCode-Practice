#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cash(n), hold(n);
        cash[0] = 0;
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i ++) {
            cash[i] = max(cash[i-1], hold[i-1]+prices[i]-fee);
            hold[i] = max(hold[i-1], cash[i-1]-prices[i]);
        }
        return cash[n-1];
    }
};