#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> hashT;
        for (int i = 0; i < 26; i ++) {
            hashT[(char)((int)'a'+i)] = 0;
        }
        
        int total = s.length();
        for (char& c: s) {
            hashT[c] += 1;   
        }
        for (char& c: t) {
            if (hashT[c] > 0) {
                hashT[c] -= 1;
                total -= 1;
            }       
        }
        return (total == 0);
    }
};