#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
    Title: 139. Word Break
    Time Complexity: O(20 x N^2)
    Space Complexity: O(N)

    Algorithm:
        1. Dynamic Programming(Top-Down)      
    
    Note:
        1. 和背包客問題很像，像這種求組合、排列的題目，都可以先從divide & conquer
           的角度切入，並轉換成top-down的DP來解。

    Date: 01/28/2022 20:57				
    Time: 7 ms  -- beat 73.40%
    Memory: 10.6 MB  -- beat 57.17%
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dp;
        unordered_set<string> dict;
        
        for (auto word: wordDict) {
            dict.insert(word);
        }
        return top_down(s, dp, dict);
    }
    
    bool top_down(string& s, unordered_map<string, int>& dp, unordered_set<string>& dict) {
        if (dict.count(s) == 1) {
            dp[s] = 1;
            return true;
        }
        
        int rightMost = (20 < s.length()) ? 20 : s.length();
        
        for (int i = 1; i < rightMost; i ++) {
            string head = s.substr(0, i);
            string tail = s.substr(i, s.length() - i);
            
            if (dict.find(head) != dict.end()) {
                if (dp[tail] != 0) { 
                    if (dp[tail] == 1) {
                        dp[s] = 1;
                        return true;
                    }
                }
                else if (top_down(tail, dp, dict)) {
                    dp[s] = 1;
                    return true;
                }
            }
        }
        
        dp[s] = -1;
        return false;
    }
};