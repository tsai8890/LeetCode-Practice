#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<unsigned long long> dp(m+1, 0);
        
        for (int i = 0; i <= n; i ++) {
            for (int j = m; j >= 0; j --) {
                if (j == 0) {
                    dp[j] = 1;
                }
                else if (i == 0) {
                    dp[j] = 0;
                }
                else {
                    if (s[i-1] == t[j-1]) {
                        dp[j] += dp[j-1];
                    }
                }
            }
        }
        return dp[m];
    }
};