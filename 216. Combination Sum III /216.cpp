#include <vector>
using namespace std;

class Solution {
    /*
        Title: 216. Combination Sum III
        Time Complexity: O(C9取k)
        Algorithm: 
            1. Recursion
                        
        Date: 12/06/2021 21:00	
        Time: 0 ms  -- beat 100.00%
        Memory: 6.5 MB  -- beat 39.77%
    */
public:
    vector<vector<int>> res;
    vector<int> cur_set;
    
    void helper(int remain, int n_used, int k, int least_can_use) {
        if (n_used == k) {
            if (remain == 0)
                res.push_back(cur_set);
            return;
        }
        
        for (int i = least_can_use; i <= 9 - (k - n_used - 1); i ++) {
            cur_set.push_back(i);
            helper(remain-i, n_used+1, k, i+1);
            cur_set.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        cur_set.clear();
        helper(n, 0, k, 1);
        return res;
    }
};