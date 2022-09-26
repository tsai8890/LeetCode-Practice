#include <vector>
using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), less<int>());
        int n = nums.size();
        vector<vector<int>> res;
        
        ll pre_i, pre_j;
        for (int i = 0; i <= n-4; i ++) {
            if (i != 0 && nums[i] == pre_i) {
                continue;
            }
            
            for (int j = i+1; j <= n-3; j ++) {
                if (j != i+1 && nums[j] == pre_j) {
                    continue;
                }
                
                int left = j+1, right = n-1;
                ll tmpTarget = (ll)(target)-(ll)(nums[i])-(ll)(nums[j]);
                ll sum, tmp;
                while (left < right) {
                    sum = nums[left] + nums[right];
                    if (sum == tmpTarget) {
                        res.push_back(vector<int>{
                            nums[i], nums[j], nums[left], nums[right]
                        });
                        
                        tmp = nums[left];
                        while (left <= n-1 && nums[left] == tmp) {
                            left++;
                        }
                    }
                    else if (sum > tmpTarget) {
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
                pre_j = nums[j];
            }
            pre_i = nums[i];
        }
        return res;
    }
};