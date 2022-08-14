#include <climits>
#include <unordered_map>
using namespace std;

/*
    Title: 397. Integer Replacement
    Time Complexity: O(N)
    Space Complexity: O(logN) - extra space

    Algorithm: 
        1. Divide & Conquer
        2. Dynamic Programming

    Note:
        1.  這題是很典型的 Divide & Conquer 題目，
            時間複雜度大略是 O(N)：
                recursion height： O(logN)
                branch factor： 2
            O(2 ^ (logN)) = O(N)

            可以利用一些數學上的觀察來優化，
            可以達到 O(logN)-time + O(1)-space。

        2.  這個解法有使用 DP 來加速，
            時間複雜度仍然是 O(N)，但是會快很多
            
        3.  Total Time Complexity: O(N)
                i.  recursion height： O(logN)
                ii. branch factor： 2
            => O(2 ^ logN) = O(N)

            Total Space Complexity: O(logN)
                i.  recursion height: O(logN)
                ii. each node space: O(1)
            => O(1 x logN) = O(logN)

    Date: 06/28/2022 21:14																			    			
    Time: 0 ms  -- beat 100.00%
    Memory: 10.3 MB  -- beat 8.63%
*/

class Solution {
public:
    int integerReplacement(int n) {
        unordered_map<long long, int> dp;
        return dfs(n, dp);
    }
    
    int dfs(long long n, unordered_map<long long, int>& dp) {
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        else {
            if (n == 1) {
                dp[n] = 0;
            }
            else if (n % 2 == 0) {
                dp[n] = 1 + dfs(n / 2, dp);
            }
            else {
                if (n <= 1) {
                    dp[n] = 1 + dfs(n+1, dp);
                }
                else {
                    dp[n] = 1 + min(dfs(n+1, dp), dfs(n-1, dp));
                }
            }
            return dp[n];
        }
    }
};