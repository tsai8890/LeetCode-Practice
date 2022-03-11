#include <vector>
using namespace std;

class Solution {
    /*
        Title: 377. Combination Sum IV
        Time Complexity: O(|nums| ^ target)
        Algorithm: 
            1. Recursion
                        
        Time Limit Exceeded
    */
public:
    void helper(int remain, vector<int>& nums, int& res) {
        if (remain <= 0) {
            if (remain == 0)
                res += 1;
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            helper(remain - nums[i], nums, res);
        }
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        helper(target, nums, res);
        return res;
    }
};