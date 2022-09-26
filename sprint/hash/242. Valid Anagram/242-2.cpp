#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> hashT(26, 0);
        for (char& c: s) {
            hashT[c-'a'] += 1;   
        }

        int total = s.length();
        for (char& c: t) {
            if (hashT[c-'a'] > 0) {
                hashT[c-'a'] -= 1;
                total -= 1;
            }       
        }
        return (total == 0);
    }
};