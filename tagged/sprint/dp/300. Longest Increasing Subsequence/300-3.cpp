#include <vector>
using namespace std;

class Solution {
public:
    int bsearch(vector<int>& nums, int end, int key) {
        int left = 0, right = end;
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
        int curLen = 1;

        for (int i = 1; i < n; i ++) {
            if (nums[i] > nums[curLen-1]) {
                nums[curLen++] = nums[i];
            }
            else {
                int insert = bsearch(nums, curLen-1, nums[i]);
                nums[insert] = nums[i];
            }
        }
        return curLen;
    }
};