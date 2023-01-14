#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n);
        vector<int> right(n);
        
        left[0] = INT_MIN;
        int leftMin = INT_MAX;
        for (int i = 1; i < n; i ++) {
            leftMin = min(leftMin, prices[i-1]);
            left[i] = max(left[i-1], prices[i]-leftMin);            
        }
        
        right[n-1] = INT_MIN;
        int rightMax = 0;
        for (int i = n-2; i >= 0; i --) {
            rightMax = max(rightMax, prices[i+1]);
            right[i] = max(right[i+1], rightMax-prices[i]);
        }
        
        int maxProfit = left[n-1];
        for (int i = 1; i < n-2; i ++) {
            maxProfit = max(maxProfit, left[i] + right[i+1]);
        }
        return max(maxProfit, 0);
    }
};