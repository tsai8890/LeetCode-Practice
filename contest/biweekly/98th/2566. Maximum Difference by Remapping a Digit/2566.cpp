#include <string>
using namespace std;

// Brute

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        int first = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] != '9') {
                first = i;
                break;
            }
        }
        
        string maxStr;
        for (int i = 0; i < s.length(); i ++) {
            maxStr = maxStr + ((s[i] == s[first]) ? '9' : s[i]);
        }
        
        string minStr;
        for (int i = 0; i < s.length(); i ++) {
            minStr = minStr + ((s[i] == s[0]) ? '0' : s[i]);
        }
        
        return stoi(maxStr) - stoi(minStr);
    }
};