#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j < m; j ++) {
                int len = wordDict[j].length();
                if (i < len || !dp[i-len]) {
                    continue;
                }
                if (s.substr(i-len, len) == wordDict[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};