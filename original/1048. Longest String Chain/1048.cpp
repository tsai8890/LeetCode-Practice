#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    Title: 1048. Longest String Chain
    Time Complexity: 
        1. O(L^2 x n)
        2. L = Max(word.length())

    Algorithm:
        1. DFS
        2. Top-Down Dynamic Programming

    Note:
        1. 這題的中心思想是 DFS + Memorization，
           值得注意的是找edge的方式，是每次從現有的string刪掉一個character，
           組成新的substring後，再丟入unordered_map檢查。

    Date: 12/28/2021 14:16						
    Time: 68 ms  -- beat 75.40%
    Memory: 19.2 MB  -- beat 52.69%
*/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> chain_length;
        for (auto& word : words) {
            chain_length[word] = -1;
        }
        
        for (auto item : chain_length) {
            string cur = item.first;
            int length = item.second;
            if (length == -1) {
                dfs(cur, chain_length);
            }
        }
        
        int max_len = 0;
        for (auto item : chain_length) {
            max_len = max(max_len, item.second);
        }
        return max_len;
    }
    
    int dfs(string cur, unordered_map<string, int>& table) {
        int max_len = 0;
        
        for (int i = 0; i < cur.length(); i ++) {
            string ancestor = cur.substr(0, i);
            ancestor += cur.substr(i+1, cur.length() - (i+1));
            
            if (table.count(ancestor) == 1 && table[ancestor] == -1) {
                max_len = max(max_len, dfs(ancestor, table));
            
            } else if (table.count(ancestor) == 1 && table[ancestor] != -1) {
                max_len = max(max_len, table[ancestor]);
            }
        }
        
        table[cur] = max_len + 1;
        return table[cur];
    }
};