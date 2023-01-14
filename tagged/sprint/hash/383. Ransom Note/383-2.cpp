#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> charSet(26, 0);
        for (char& c: magazine) {
            charSet[c-'a'] ++;
        }
        
        for (char& c: ransomNote) {
            if (charSet[c-'a'] == 0) {
                return false;
            }
            charSet[c-'a'] --;
        }
        return true;
    }
};