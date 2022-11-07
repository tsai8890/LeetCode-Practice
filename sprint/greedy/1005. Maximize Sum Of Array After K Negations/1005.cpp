#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
            else {
                break;
            }
            
            if (k == 0) {
                break;
            }
        }
        
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
        }
        
        if (k == 0) {
            return sum;   
        }
        else {
            sort(nums.begin(), nums.end());
            return (k % 2 == 0) ? sum : sum - 2*nums[0];
        }
    }
};