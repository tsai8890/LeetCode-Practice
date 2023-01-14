#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(N+1, 
                                       vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        vector<int> nZeros(N+1, 0), nOnes(N+1, 0);
        for (int i = 0; i <= N; i ++) {
            int zeros = 0, ones = 0;
            if (i > 0) {
                for (char& ch: strs[i-1]) {
                    if (ch == '0') nZeros[i]++;
                    else if (ch == '1') nOnes[i]++;
                }
            }
        }
        return helper(N, m, n, strs, nZeros, nOnes, dp);    
    }

    int helper(int N, int m, int n, vector<string>& strs, vector<int>& nZeros, 
                                    vector<int>& nOnes, vector<vector<vector<int>>>& dp) {
        if (N == 0) {
            return 0;
        }
        if (dp[N][m][n] != -1) {
            return dp[N][m][n];
        }

        if (nZeros[N] <= m && nOnes[N] <= n) {
            dp[N][m][n] = max(helper(N-1, m, n, strs, nZeros, nOnes, dp),
                              helper(N-1, m-nZeros[N], n-nOnes[N], strs, nZeros, nOnes, dp) + 1);
        }
        else {
            dp[N][m][n] = helper(N-1, m, n, strs, nZeros, nOnes, dp);
        }
        return dp[N][m][n];
    }
};