#include <vector>
using namespace std;

class Solution {
    /*
        Title: 167. Two Sum II - Input Array Is Sorted
        Time Complexity: O(N)
        Note:
            1. Two Pointer           
        
        Date: 12/07/2021 10:49		
        Time: 4 ms  -- beat 87.46%
        Memory: 9.4 MB  -- beat 93.83%
    */
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int sum;
        
        while (left < right) {
            sum = numbers[left] + numbers[right];
            
            if (sum < target) {
                left += 1;
            } else if (sum > target) {
                right -= 1;    
            } else {
                vector<int> ret = {left+1, right+1};
                return ret;
            }
        }
        
        vector<int> err = {};
        return err;
    }
};