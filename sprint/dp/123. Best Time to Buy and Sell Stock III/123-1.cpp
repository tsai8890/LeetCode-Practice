#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        const int MIN = -100005;
        vector<int> buy1(n), sell1(n);
        vector<int> buy2(n), sell2(n);
        
        for (int i = 0; i < n; i ++) {
            buy1[i] = (i == 0) ? -prices[i] : max(buy1[i-1], -prices[i]);
            sell1[i] = (i < 1) ? MIN : max(buy1[i-1]+prices[i], sell1[i-1]);
            buy2[i] = (i < 2) ? MIN : max(sell1[i-1]-prices[i], buy2[i-1]);
            sell2[i] = (i < 3) ? MIN : max(buy2[i-1]+prices[i], sell2[i-1]);
        }
        return max(0, max(sell1.back(), sell2.back()));
    }
};