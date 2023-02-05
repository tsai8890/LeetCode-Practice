#include <vector>
#include <string>
using namespace std;

// Prefix Sum

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n, 0);
        for (int i = 0; i < n; i ++) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length()-1])) {
                pref[i] = 1;
            }
            if (i != 0) {
                pref[i] += pref[i-1];
            }
        }
        
        int q = queries.size();
        vector<int> res(q);
        for (int i = 0; i < q; i ++) {
            res[i] = pref[queries[i][1]];
            if (queries[i][0] != 0) {
                res[i] -= pref[queries[i][0]-1];
            }
        }
        return res;
    }
    
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
};