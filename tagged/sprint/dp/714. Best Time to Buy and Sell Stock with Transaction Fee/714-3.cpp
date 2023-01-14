#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int begin = prices[0], end = prices[0];
        int totalProfit = 0, curProfit = -fee;
        int n = prices.size();
        
        for (int i = 1; i < n; i ++) {
            if (prices[i] >= end) {
                curProfit += prices[i] - end;
                end = prices[i];
            }
            else if (prices[i] < end - fee || prices[i] < begin) {
                if (curProfit > 0) {
                    totalProfit += curProfit;
                    curProfit = 0;
                }
                curProfit = -fee;
                begin = end = prices[i];
            }
        }
        
        if (curProfit > 0) {
            totalProfit += curProfit;
        }
        return totalProfit;
    }
};