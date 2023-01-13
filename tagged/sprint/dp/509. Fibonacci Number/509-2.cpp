#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fib(int n) {
        unordered_map<int, int> dp;
        return helper(n, dp);
    }

    int helper(int n, unordered_map<int, int>& dp) {
        if (n == 0 || n == 1) {
            return n;
        }

        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        dp[n] = helper(n-1, dp) + helper(n-2, dp);
        return dp[n];
    }
};