#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cash, prevCash = 0;
        int hold, prevHold = -prices[0];
        
        for (int i = 1; i < n; i ++) {
            cash = max(prevCash, prevHold+prices[i]);
            hold = max(prevHold, prevCash-prices[i]);
            prevCash = cash;
            prevHold = hold;
        }
        return prevCash;
    }
};