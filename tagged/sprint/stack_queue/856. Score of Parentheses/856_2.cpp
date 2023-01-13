#include <string>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int totalScore = 0;
        int n = s.length(), bal = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                bal += 1;
            }
            else {
                bal -= 1;
                if (s[i-1] == '(') {
                    totalScore += 1 << bal;
                } 
            }
        }
        return totalScore;
    }
};