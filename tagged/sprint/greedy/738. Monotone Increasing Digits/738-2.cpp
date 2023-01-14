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
        int flag = len-1;
        for (int i = len-1; i >= 0; i --) {
            if (digits[i-1] > digits[i]) {
                flag = i-1;
                digits[flag] --;
            }
        }
        
        if (flag == len-1) {
            return n;
        }
        else {
            for (int i = flag+1; i < len; i ++) {
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