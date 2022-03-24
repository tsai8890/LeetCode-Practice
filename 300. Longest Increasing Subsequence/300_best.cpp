#include <vector>
using namespace std;

/*
    Title: 300. Longest Increasing Subsequence
    Time Complexity: O(nlogn)
    Space Complexity: O(n)

    Algorithm: 
        1. Dynamic Programming
            
    Note:   
        1. 很猛，該記一下。
        2. dp[i]: 長度為i+1，最佳的遞增序列的結尾元素
            definition: 
                最佳的遞增序列指的是結尾元素最小的遞增序列
            
            Transition:
                i. dp = {nums[0]} #初始化
                1i. i = 1 to n-1，每次看到nums[i]，先檢查nums[i]介於dp array的哪兩個元素之間，
                   可以使用二分搜尋(因為dp陣列一定是遞增的)，
                   會有三種情況
                        a. nums[i] > dp.back() 
                            -> 直接dp.push_back(nums[i])
                        b. dp[j] <= nums[i] <= dp[j+1]
                            -> dp[j+1] = nums[i]
                        c. nums[i] <= dp[0]
                            -> dp[0] = nums[i]
                iii. 最後回傳dp.size()即可

    Date: 03/24/2022 20:49							
    Time: 3 ms  -- beat 99.69%
    Memory: 10.3 MB  -- beat 86.57%
*/

class Solution {
public:
    int bsearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (target < nums[mid]) {
                right = mid;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return left;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        int n = nums.size();
        
        for (int i = 1; i < n; i ++) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            }
            else {
                int insert = bsearch(dp, nums[i]);
                dp[insert] = nums[i];                
            }
        }
        return dp.size();
    }
};