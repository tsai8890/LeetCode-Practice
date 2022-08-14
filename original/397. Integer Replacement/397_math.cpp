#include <climits>
using namespace std;

/*
    Title: 397. Integer Replacement
    Time Complexity: O(logN)
    Space Complexity: O(logN) - extra space

    Algorithm: 
        1. Divide & Conquer
        2. Math

    Note:
        1.  這題是很典型的 Divide & Conquer 題目，
            時間複雜度大略是 O(N)：
                recursion height： O(logN)
                branch factor： 2
            O(2 ^ (logN)) = O(N)

            可以利用一些數學上的觀察來優化，
            可以達到 O(logN)-time + O(1)-space。

        2.  這個解法使用到數學上的觀察，
            若 n 是奇數：
                i.  若 n 的倒數第二個 bit 是 1：
                    n = n + 1 會產生結尾兩個 bit 都是 0，
                    是最優解
                    Exception: n = 3

                ii. 若 n 的倒數第二個 bit 是 0：
                    n = n - 1 會產生結尾兩個 bit 都是 0，
                    是最優解

            如此一來，遞迴所消耗的資源會大幅減少，
            時間複雜度也可以降到 O(logN)，因為 branch factor = 1
            
        3.  Total Time Complexity: O(logN)
                i.  recursion height： O(logN)
                ii. branch factor： 1
            => O(1 ^ logN) = O(logN)

            Total Space Complexity: O(logN)
                i.  recursion height: O(logN)
                ii. each node space: O(1)
            => O(1 x logN) = O(logN)

    Date: 06/29/2022 12:21																				    			
    Time: 0 ms  -- beat 100.00%
    Memory: 5.9 MB  -- beat 84.45%
*/

class Solution {
public:
    int integerReplacement(int n) {
        return dfs(n);
    }
    
    int dfs(long long n) {
        if (n == 1) {
            return 0;
        }
        else if (n % 2 == 0) {
            return 1 + dfs(n / 2);
        }
        else {
            if (n != 3 && (n >> 1) & 1 != 0) {
                return 1 + dfs(n+1);
            }
            else {
                return 1 + dfs(n-1);
            }
        }
    }
};