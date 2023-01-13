#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cash = {0};
        vector<int> cooldown = {0};
        vector<int> hold = {-prices[0]};
        
        for (int i = 1; i < n; i ++) {
            cash.push_back(max(cash[i-1], cooldown[i-1]));
            cooldown.push_back(hold[i-1]+prices[i]);
            hold.push_back(max(hold[i-1], cash[i-1]-prices[i]));
        }
        return max(cash[n-1], cooldown[n-1]);
    }
};