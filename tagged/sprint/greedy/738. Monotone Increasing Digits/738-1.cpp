#include <vector>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> digits;
        int tmp = n;
        while (tmp > 0) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        int len = digits.size();
        int start = 0, end = 0;
        for (int i = 1; i < len; i ++) {
            if (digits[i] > digits[i-1]) {
                start = end = i;
            }
            else if (digits[i] == digits[i-1]) {
                end = i;
            }
            else {
                break;
            }
        }
        
        if (end == len-1) {
            return n;
        }
        else {
            digits[start] --;
            for (int i = start+1; i < len; i ++) {
                digits[i] = 9;
            }
            
            int res = 0;
            for (int i = 0; i < len; i ++) {
                res = res*10 + digits[i];
            }
            return res;
        }
    }
};