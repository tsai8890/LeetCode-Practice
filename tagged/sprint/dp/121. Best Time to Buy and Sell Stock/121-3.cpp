#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int highest = prices.back();
        
        int maxProfit = 0;
        for (int i = n-2; i >= 0; i --) {
            maxProfit = max(maxProfit, highest-prices[i]);
            highest = max(prices[i], highest);
        }
        return maxProfit;
    }
};