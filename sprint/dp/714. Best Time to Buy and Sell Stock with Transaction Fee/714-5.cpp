#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int end = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i ++) {
            if (prices[i] > end + fee) {
                profit += (prices[i] - end - fee);
                end = prices[i] - fee;
            }
            else if (prices[i] < end) {
                end = prices[i];
            }
        }
        return profit;
    }
};