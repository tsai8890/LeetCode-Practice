#include <climits>
using namespace std;

/*
    Title: 397. Integer Replacement
    Time Complexity: O(logN)
    Space Complexity: O(1) - extra space

    Algorithm: 
        1. Math

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
        
        3.  因為 branch factor = 1，所以直接用迴圈解其實就可以了，
            這樣空間複雜度可以再降到 O(1)

        4.  Total Time Complexity: O(logN)
                i.  recursion height： O(logN)
                ii. branch factor： 1
            => O(1 ^ logN) = O(logN)

            Total Space Complexity: O(1)

    Date: 06/29/2022 12:47																					    			
    Time: 0 ms  -- beat 100.00%
    Memory: 5.8 MB  -- beat 97.80%
*/

class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        long long int N = n;
        while (N != 1) {
            if (N % 2 == 0) {
                N = N / 2;
            }
            else {
                if (N != 3 && (N >> 1) & 1 != 0) {
                    N += 1;
                }
                else {
                    N -= 1;
                }
            }
            count += 1;
        }
        return count;
    }
};