#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp = {0};

        int x = dp.size();
        while (x <= n) {
            int minVal = 10002;
            for (int i = 1; i*i <= x; i ++) {
                minVal = min(minVal, dp[x-i*i]);
            }
            dp.push_back(minVal+1);
            x++;
        }
        return dp[n];
    }
};