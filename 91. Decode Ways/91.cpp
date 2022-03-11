#include <vector>
#include <string>
using namespace std;

/*
    Title: 91. Decode Ways
    Time Complexity: O(n)
    Space Complexity: O(n)
        - 如果只記上一格，可以到O(1)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. dp[i]: s[0..i]可以decode的方法數
           轉移方程:
                curInt = to_digit(s[i-1], s[i])
                
                if (s[i-1] == '0' && s[i] == '0')      // case 1
                    dp[i] = 0
                
                else if (s[i-1] != '0' && s[i] == '0') // case 2
                    dp[i] = (curInt <= 26) ? dp[i-2] : 0
                
                else if (s[i-1] == '0' && s[i] != '0') // case 3
                    dp[i] = dp[i-1]

                else                                   // case 4 
                    dp[i] = (curInt <= 26) ? dp[i-1]+dp[i-2] : dp[i-1]

        2. dp值應該都要不是0，如果某回合算完首次發現dp[i]=0，說明該回合一定是case1或case2，
           因為case3、case4一定會讓dp[i]=先前的dp值而不為0。

           而case1、case2都是s[i]='0'，代表在decode s的時候，s[i]跟s[i+1]中間一定會切一刀，
           但是切完之後，一定會發現s[0..i]是無法decode的(因為dp[i]=0)，所以對於整個s一定沒有
           任何的decode方法，可以直接回傳0。

        3. 想法不難，但是實作起來很髒...，要處理很多edge cases

    Date: 01/31/2022 17:29						
    Time: 0 ms  -- beat 100.00%
    Memory: 6.1 MB  -- beat 91.57%
*/

class Solution {
public:
    int to_digit(char a, char b) {
        return 10 * (a-'0') + b-'0';
    }

    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        
        int n = s.length();
        vector<int> dp(n);
        
        if (n == 1) {
            return 1;
        }
        else {
            dp[0] = 1;
            
            if (s[1] == '0' && to_digit(s[0], s[1]) > 26) {
                return 0;
            }
            else if (s[1] == '0' || to_digit(s[0], s[1]) > 26) {
                dp[1] = 1;
            }
            else {
                dp[1] = 2;
            }

            for (int i = 2; i < n; i ++) {
                int curInt = to_digit(s[i-1], s[i]);
                
                if (s[i-1] == '0' && s[i] == '0') {
                    dp[i] = 0;
                }
                else if (s[i-1] != '0' && s[i] == '0') {
                    dp[i] = (curInt <= 26) ? dp[i-2] : 0;
                }
                else if (s[i-1] == '0' && s[i] != '0') {
                    dp[i] = dp[i-1];
                }
                else {
                    dp[i] = (curInt <= 26) ? dp[i-1]+dp[i-2] : dp[i-1];
                }
                
                if (dp[i] == 0)
                    return 0;
            }
            return dp.back();
        }
    }
};