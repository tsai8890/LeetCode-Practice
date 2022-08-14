#include <vector>
using namespace std;

class Solution {
    /*
        Title: 189. Rotate Array
        Time Complexity: O(N)
        Algorithm: 
            1. Two Pointer
        
        Date: 12/06/2021 23:59	
        Time: 32 ms  -- beat 47.61%
        Memory: 26.2 MB  -- beat 7.25%
    */
public:
    void rotate(vector<int>& nums, int k) {
        long long int left = 0;
        left = (left - k + k * nums.size()) % nums.size();

        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            int index = (left + i) % nums.size();
            res.push_back(nums[index]);            
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            nums[i] = res[i];          
        }
    }
};