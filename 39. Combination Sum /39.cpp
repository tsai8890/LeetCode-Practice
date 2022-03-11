#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 39. Combination Sum
        Time Complexity: O(N^M)
        Algorithm: 
            1. Recursion
                        
        Date: 12/03/2021 21:11
        Time: 32 ms  -- beat 30.25%
        Memory: 21.2 MB  -- beat 22.66%
    */
public:
    void recursion(int remain, int index, vector<int> cur_set,
                    vector<vector<int>>& res, vector<int> candidates) {
        
        if (index == candidates.size()) {
            if (remain == 0)
                res.push_back(cur_set);
            return;
        }
        
        if (remain < candidates[index]) {
            if (remain == 0)
                res.push_back(cur_set);
            return;
        }
        
        int times = remain / candidates[index];
        for (int i = 0; i <= times; i ++) {
            recursion(remain - candidates[index] * i, index + 1, cur_set, res, candidates);
            cur_set.push_back(candidates[index]);
        } 
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur_set;
        vector<vector<int>> res;
        recursion(target, 0, cur_set, res, candidates);
        return res;
    }
};