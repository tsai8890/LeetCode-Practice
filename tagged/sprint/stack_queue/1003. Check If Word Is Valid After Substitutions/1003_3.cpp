#include <stack>
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        int i = 0, j = 0;
        for (; i < n; i ++) {
            if (s[i] == 'c')  {
                if (j < 2 || (s[j-1] != 'b' || s[j-2] != 'a')) {
                    return false;
                }
                j -= 2;
            }
            else {
                s[j++] = s[i];
            }
        }
        return (j == 0);
    }
};