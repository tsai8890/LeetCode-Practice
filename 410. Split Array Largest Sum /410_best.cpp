#include <vector>
#include <climits>
using namespace std;

class Solution {
    /*
        Title: 410. Split Array Largest Sum
        Time Complexity:
            1. O(n * log(2^31-1)) = O(n)

        Algorithm:
            1. Binary Search
            2. Greedy

        Note:
            1. Compare(nums, m, k): 判斷最佳解是否小於等於k，
                i. 判斷方法有點Greedy

            2. 透過Binary Search，left=0, right=INT_MAX，
               搭配Compare()，即可透過窮舉+二分搜尋找出最佳解

            3. 是個天才方法，學起來

        Date: 12/18/2021 18:13						
        Time: 0ms  -- beat 100.00%
        Memory: 8.1 MB  -- beat 14.39%
    */
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (compare(nums, m, mid) == 1) {
                left = mid + 1;
            } else {
                right = mid;
            }    
        }
        return left;
    }
    
    int compare(vector<int>& nums, int m, int k) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > k) {
                return 1;
            }
        }
        
        int cur_sum = 0;
        int cur_count = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (cur_sum + nums[i] <= k) {
                cur_sum += nums[i];
            } else {
                cur_sum = nums[i];
                cur_count += 1;
            }
        }
        cur_count += 1;
        return (cur_count <= m) ? -1 : 1;
    }
};