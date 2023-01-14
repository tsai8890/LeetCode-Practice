#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int end = prices[0];
        int profit = 0;
        bool first = true;
        int n = prices.size();
        for (int i = 1; i < n; i ++) {
            if (first) {
                if (prices[i] > end + fee) {
                    profit += (prices[i] - end - fee);
                    end = prices[i];
                    first = false;
                }
                else if (prices[i] < end) {
                    end = prices[i];
                }
            }
            else {
                if (prices[i] > end) {
                    profit += prices[i] - end;
                    end = prices[i];
                }
                else if (prices[i] < end - fee) {
                    first = true;
                    end = prices[i];
                }
            }
        }
        return profit;
    }
};