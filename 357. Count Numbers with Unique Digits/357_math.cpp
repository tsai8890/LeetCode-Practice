#include <vector>
using namespace std;

/*
    Title: 357. Count Numbers with Unique Digits
    Time Complexity: O(n)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Math :)
        
    Note:
        1. 討論最高位是不是0，若不是0，則總共有 9x9x8x7...種;
           若是0，則依次討論從最高位起連續的0有幾個。

           數學題 XD

    Date: 05/12/2022 15:22												
    Time: 0 ms  -- beat 100.00%
    Memory: 5.8 MB  -- beat 83.42%
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 10;
        }
        else {
            int res1 = 9;
            int x = 9;
            for (int i = 1; i < n; i ++) {
                res1 *= (x--);
            }

            int res2 = 10;
            int cur = 9, y = 9;
            for (int i = 1; i < n-1; i ++) {
                cur *= (y--);
                res2 += cur;
            }
            
            return res1 + res2;
        }
    }
};