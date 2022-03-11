#include <vector>
#include <numeric>

using namespace std;

class Solution {
    /*
        Title: 2090. K Radius Subarray Averages
        Time Complexity: O(N)
        Algorithm: 
            1. Sliding Window(Two Pointer)
            2. 注意邊界測資!
                        
        Date: 12/03/2021 02:38	
        Time: 184 ms  -- beat 94.87%
        Memory: 130 MB  -- beat 65.69%
    */
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0)
            return nums;
            
        vector<int> avgs(nums.size(), -1);
        if (nums.size() < 2 * k + 1) {
            return avgs;
        }
        
        long long int sum = 0;
        for (int i = 0; i < 2 * k; i ++) {
            sum += (long long int)(nums[i]);
        }

        for (int i = k; i < avgs.size() - k; i ++) {
            sum += nums[i + k];
            avgs[i] = sum / (2 * k + 1);
            sum -= nums[i - k];
        }
        return avgs;
    }
};