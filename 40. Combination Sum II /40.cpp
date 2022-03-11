#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    /*
        Title: 40. Combination Sum II
        Time Complexity: O(N^M)
        Algorithm: 
            1. Recursion
        
        Note:
            1. Using reference to pass parameters will save much 
               time duplicating the objects!!!
                        
        Date: 12/06/2021 20:42	
        Time: 4 ms  -- beat 89.88%
        Memory: 10.9 MB  -- beat 40.22%
    */
public:
    vector<vector<int>> res;
    vector<int> keys;
    unordered_map<int, int> candidate_table;
    
    void dfs(int index, int remain, vector<int>& cur_set) {
        if (index == keys.size()) {
            if (remain == 0)
                res.push_back(cur_set);
            return;
        }
        
        if (remain == 0) {
            res.push_back(cur_set);
            return;
        }
        
        if (candidate_table[keys[index]] > 0 && remain >= keys[index]) {
            cur_set.push_back(keys[index]);
            candidate_table[keys[index]] -= 1;
            dfs(index, remain - keys[index], cur_set);
            cur_set.pop_back();
            candidate_table[keys[index]] += 1;
        }
        
        dfs(index + 1, remain, cur_set);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidate_table.clear();
        keys.clear();
        res.clear();
        
        for (int i = 0; i < candidates.size(); i ++) {
            if (candidate_table.count(candidates[i]) == 0) {
                candidate_table[candidates[i]] = 1;
                keys.push_back(candidates[i]);
            } else {
                candidate_table[candidates[i]] += 1;
            }
        }
        
        vector<int> cur_set;
        dfs(0, target, cur_set);
        return res;
    }
};