#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cash = 0, hold = -prices[0];
        
        for (int i = 1; i < n; i ++) {
            cash = max(cash, prices[i]+hold);
            hold = max(hold, -prices[i]);
        }
        return cash;
    }
};