#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 279. Perfect Squares
    Time Complexity: O(n^2)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 可以用static vector來加速，當測資比數增多時，速度會得到超大幅提升

        2. dp[i]: amount為i時，最小的組合長度
            i.   for j in [1..sqrt(i)]:
                    計算以j^2為結尾的所有組合
                    更新dp[i] 
            ii.  base case: dp[0] = 0
        
    Date: 04/20/2022 11:05										
    Time: 7 ms  -- beat 95.49%
    Memory: 6.4 MB  -- beat 81.30%
*/

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp = {0};
        
        while (dp.size() <= n) {
            int m = dp.size();
            int sol = 10002;
            for (int i = 1; i*i <= m; i ++) {
                sol = min(sol, dp[m-i*i]+1);
            }
            dp.push_back(sol);
        }
        return dp[n];
    }
};