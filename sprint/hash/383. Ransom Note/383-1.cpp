#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> uMap;
        for (char& c: magazine) {
            if (uMap.find(c) == uMap.end()) {
                uMap[c] = 0;
            }
            uMap[c] ++;
        }
        
        for (char& c: ransomNote) {
            if (uMap.find(c) == uMap.end() || uMap[c] == 0) {
                return false;
            }
            uMap[c] --;
        }
        return true;
    }
};