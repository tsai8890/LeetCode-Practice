#include <vector>
#include <numeric>

using namespace std;

class Solution {
    /*
        Title: 2090. K Radius Subarray Averages
        Time Complexity: O(N)
        Algorithm: 
            1. Prefix-Sum Array
            2. 注意邊界測資!
                        
        Date: 12/03/2021 03:09	
        Time: 204 ms  -- beat 67.37%
        Memory: 136.6 MB  -- beat 47.17%
    */
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0)
            return nums;
        
        vector<int> avgs(nums.size(), -1);
        if (nums.size() < 2 * k + 1) {
            return avgs;
        }

        vector <long long int> pre_sum(nums.size());
        pre_sum[0] = nums[0];
        for (int i = 1; i < pre_sum.size(); i ++) {
            pre_sum[i] = pre_sum[i-1] + nums[i];
        }
        
        for (int i = k; i < avgs.size() - k; i ++) {
            if (i == k) {
                avgs[i] = pre_sum[i + k] / (2 * k + 1);
            } else {
                avgs[i] = (pre_sum[i + k] - pre_sum[i - k - 1]) / (2 * k + 1);
            }
        }
        
        return avgs;
    }
};