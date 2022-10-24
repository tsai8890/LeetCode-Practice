#include <vector>
using namespace std;

class Solution {
public:
    int bsearch(vector<int>& nums, int key) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < key) {
                left = mid + 1;
            }
            else if (key < nums[mid]) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return right + 1;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub = {nums[0]};
        
        for (int i = 1; i < n; i ++) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            }
            else {
                int insert = bsearch(sub, nums[i]);
                sub[insert] = nums[i];
            }
        }
        return sub.size();
    }
};