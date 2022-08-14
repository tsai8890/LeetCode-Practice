#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Title: 926. Flip String to Monotone Increasing
    Time Complexity: O(2xn)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1. 典型的 bottom-up DP 題目

        2. Dynamic Programming:
            dp[i][j]: 將s[0..i] 變成 monotone，且s[i]最後是j的最小cost
            j in {0, 1}

            DP Transition
                i.      dp[0][0] = s[i] - '0';
                ii.     dp[0][1] = '1' - s[i];
                iii.    dp[i][j] = dp[i-1][0] + s[i] - '0', if j = 0
                        dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + '1' - s[i], if i = 1
        
        3. 這題其實只需要 1 rows x 2 columns 的 dp array，
           甚至可以直接用兩個變數 zeros, ones 來儲存資訊就好。
           
            Representation:
                zeros: dp[i][0]
                ones: dp[i][1]

            Transition(與原本dp幾乎一樣):
                ones = min(zeros, ones) + ('1' - s[i]);
                zeros = zeros + (s[i] - '0');

                Note: 順序不能變，因為 ones 會用到前一個zeros & ones的值，
                      若先更新zeros，前一個zeros的值就不見了。

    Date: 06/03/2022 00:44															    			
    Time: 22 ms  -- beat 95.04%
    Memory: 11 MB  -- beat 77.59%
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int zeros = 0, ones = 0;
        for (int i = 0; i < n; i ++) {
            ones = min(zeros, ones) + ('1' - s[i]);
            zeros = zeros + (s[i] - '0');
        }
        return min(zeros, ones);
    }
};