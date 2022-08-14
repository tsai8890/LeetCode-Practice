#include <vector>
#include <string>
using namespace std;

class Solution {
    /*
        Title: 792. Number of Matching Subsequences
        Time Complexity:
            1. O(s.length() x words.length())

        Algorithm:
            1. Brutal Force
            
        TLE
    */
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        
        for (int i = 0; i < words.size(); i ++) {
            if (words[i].length() > s.length()) {
                continue;
            } else {
                count = (match(s, words[i])) ? count + 1 : count;
            }
        }        
        return count;
    }
    
    bool match(string& s, string& word) {
        int i = 0, j = 0;
        while (i < s.length() && j < word.length()) {
            if (word[j] == s[i]) 
                j += 1;
            i += 1;
        }
        return j == word.length();
    }
};
