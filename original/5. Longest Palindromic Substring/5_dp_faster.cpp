#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
    Title: 5. Longest Palindromic Substring
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Algorithm: 
        1. Dynamic Programming
            
    Note:   
        1. 與本題原本的dp解法一樣，只是變成只記目前這行(cur)以及前一行(last)，
           每回合算完後再cur.swap(last)，把cur跟last交換。

        2. 這解法可以省空間也省時間(存取memory的時間)
        3. vector::swap(vector): 是O(1)-time!!

    Date: 02/10/2022 00:27							
    Time: 403 ms  -- beat 28.14%
    Memory: 7.3 MB  -- beat 73.96%
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<bool> cur(n);
        vector<bool> last(n);
        
        int maxStart = 0, maxLen = 1;
        for (int j = 0; j < n; j ++) {
            for (int i = j; i >= 0; i --) {
                if (i == j) {
                    cur[i] = true;
                }
                else if (i + 1 == j) {
                    cur[i] = (s[i] == s[j]);
                }
                else {
                    if (s[i] == s[j] && last[i+1]) {
                        cur[i] = true;
                    }
                    else {
                        cur[i] = false;
                    }
                }
                
                if (cur[i] && j-i+1 > maxLen) {
                    maxStart = i;
                    maxLen = j-i+1;
                }
            }
            cur.swap(last);
        }
        return s.substr(maxStart, maxLen);
    }
};