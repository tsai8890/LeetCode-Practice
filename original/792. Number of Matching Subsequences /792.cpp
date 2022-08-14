#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
    /*
        Title: 792. Number of Matching Subsequences
        Time Complexity:
            1. O(s.length() + words.length())

        Algorithm:
            1. Bucket Sorting

        Note:
            1. 利用bucket儲存每個words的開頭，只要遍歷過s一次，
               就可以把所有words比對過一次。

            2. 猛方法，學起來，字串可以這樣搞。

        Date: 12/17/2021 23:28						
        Time: 124ms  -- beat 96.31%
        Memory: 47.9 MB  -- beat 71.15%
    */
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<char*>> table(128);
        char words_cstr[words.size()][51];
        for (int i = 0; i < words.size(); i ++) {
            strcpy(words_cstr[i], words[i].c_str());     
            table[words[i][0]].push_back(words_cstr[i]);
        }
        
        int count = 0;
        for (int i = 0; i < s.length(); i ++) {
            vector<char*> to_move = table[s[i]];
            table[s[i]].clear();
            for (int j = 0; j < to_move.size(); j ++) {
                char* substring = to_move[j];
                table[substring[1]].push_back(substring + 1);
            }
        }

        // Return the number of words which ends up with '\0'
        return table[0].size();
    }
};