#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size();
        vector<vector<int>> res;
        int pre_i = 0;
        for (int i = 0; i < n-2; i ++) {
            if (i != 0 && nums[i] == pre_i) {
                continue;
            }
            
            int left = i+1, right = n-1;
            int sum, tmp;
            int target = -nums[i];
            while (left < right) {
                sum = nums[left] + nums[right];
                if (sum == target) {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    tmp = nums[right];
                    while (right >= 0 && nums[right] == tmp) {
                        right--;
                    }
                }
                else if (sum > -nums[i]) {
                    tmp = nums[right];
                    while (right >= 0 && nums[right] == tmp) {
                        right--;
                    }
                }
                else {
                    tmp = nums[left];
                    while (left <= n-1 && nums[left] == tmp) {
                        left++;
                    }
                }
            }
            pre_i = nums[i];
        }
        return res;
    }
};