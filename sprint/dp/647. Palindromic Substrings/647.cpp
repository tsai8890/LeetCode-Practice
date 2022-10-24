#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[n][n];
        
        int sum = 0;
        for (int i = n-1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (j == i || j == i+1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : false;
                }
                sum += (dp[i][j]) ? 1 : 0;
            }
        }
        return sum;
    }
};