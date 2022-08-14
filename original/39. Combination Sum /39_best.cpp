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
        
        Note:
            1. Using reference to pass parameters will save much 
               time duplicating the objects!!!
                        
        Date: 12/06/2021 20:11
        Time: 0 ms  -- beat 100.00%
        Memory: 11.1 MB  -- beat 53.69%
    */
public:
    vector<vector<int>> res;

    void recursion(int remain, int index, vector<int>& cur_set, vector<int>& candidates) {
        if (index == candidates.size()) {
            if (remain == 0)
                res.push_back(cur_set);
            return;
        }

        if (remain >= candidates[index]) {
            cur_set.push_back(candidates[index]);
            recursion(remain - candidates[index], index, cur_set, candidates);
            cur_set.pop_back();
        }

        recursion(remain, index + 1, cur_set, candidates);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        vector<int> cur_set;
        recursion(target, 0, cur_set, candidates);
        return res;
    }
};