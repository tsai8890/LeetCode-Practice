#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Title: 516. Longest Palindromic Subsequence
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Algorithm: 
        1. Dynamic Programming
            
    Note:   
        1. 和原始DP解法完全一樣，差別只在我們只記目前這行(cur)跟前一行(last)，總共兩行。
           每次算完cur之後，就call cur.swap(last)，這樣就可以O(1)-time更新last了。

        2. 這解法可以省空間也省時間(存取memory的時間)
        
        3. vector::swap(vector): 是O(1)-time!!

    Date: 02/10/2022 00:02						
    Time: 52 ms  -- beat 94.65%
    Memory: 6.5 MB  -- beat 97.80%
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<short> cur(n, 0);
        vector<short> last(n, 0);
        
        for (int j = 0; j < n; j ++) {
            for (int i = j; i >= 0; i --) {
                if (i == j) {
                    cur[i] = 1;
                    continue;
                }
                
                if (s[i] == s[j]) {
                    cur[i] = last[i+1] + 2;
                }
                else {
                    cur[i] = max(cur[i+1], last[i]);
                }
            }
            cur.swap(last);
        }
        return last.front();
    }
};