#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int cash = 0;
        int hold = -prices[0];
        
        for (int i = 1; i < n; i ++) {
            int tmp = cash;
            cash = max(cash, hold+prices[i]-fee);
            hold = max(hold, tmp-prices[i]);
        }
        return cash;
    }
};