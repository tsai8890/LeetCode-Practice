#include <vector>
using namespace std;

/*
    Title: 357. Count Numbers with Unique Digits
    Time Complexity: O(n)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. dp[i]: 在[0, 10^i)中，所有符合條件(unique digits)的數字個數
        
        2. DP Transition:
            i. 將dp[i]分為兩個部分討論，最高位是不是0 / 最高位是0
                a. 最高位是0，則等同於dp[i-1]
                b. 最高位不是0，則等同於 9 x (P9取(i-1)) 
                
                Transition function: dp[i] = dp[i-1] + 9x(P9取(i-1))

        3. 這題的DP想法跟其他DP題目蠻不一樣的，值得記一下

    Date: 05/14/2022 02:07												
    Time: 0 ms  -- beat 100.00%
    Memory: 6.1 MB  -- beat 17.42%
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp = {1, 10};
        if (n <= 1) {
            return dp[n];
        }
        
        int base = 9;
        int multiply = 9;
        for (int i = 2; i <= n; i ++) {
            base *= multiply;
            dp.push_back(dp[i-1] + base);
            multiply -= 1;
        }
        return dp[n];
    }
};