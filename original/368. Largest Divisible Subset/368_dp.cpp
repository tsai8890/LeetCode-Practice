#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 368. Largest Divisible Subset
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1. 這題和 LIS (Longest Increasing Sequence) 的精神是一樣的，
           也是典型的 bottom-up DP 題型
           
           這題能使用類似 LIS 的解法，關鍵是要先排序。
           題目要求任兩個數字都要能整除，可以把這個題敘改為「升冪排序後，『每個數字%前一個數字都為0』」  
           如此一來，便可以使用類似 LIS 的解法來解決了。

        2. DP Transition
            0.  nums = sort(nums)
            i.  dp[i]: 以 nums[i] 為結尾的所有符合條件的 subsequence 中，最大的長度
            ii. dp[i] = max(dp[j] for j in [0..i-1] if nums[i] % nums[j] == 0) + 1
        
        3. 這題要求的不是 largest subset 的大小，而是要回傳該 subset，
           因此需要記錄在算 dp[i] 時，所選擇的最大的 dp[j]，
           需要把每個 dp[i] 計算時使用的最好的 dp[j] 的 j 記錄下來，
           等全部算完後便可以使用剛剛的紀錄直接 O(n) 回溯，拼出 largest subset。

    Date: 05/24/2022 17:51															
    Time: 54 ms  -- beat 82.86%
    Memory: 8.8 MB  -- beat 75.34%
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n);
        
        int largest_index = 0;
        for (int i = 1; i < n; i ++) {
            int max_sublen = 0;
            parent[i] = i;
            for (int j = 0; j < i; j ++) {
                if (nums[i] % nums[j] == 0) {
                    if (max_sublen == 0 || dp[j] > max_sublen) {
                        max_sublen = dp[j];
                        parent[i] = j;
                    }
                }
            }
            
            dp[i] = max_sublen + 1;
            if (dp[i] > dp[largest_index]) {
                largest_index = i;
            }
        }

        vector<int> result;
        int curPos = largest_index;
        result.push_back(nums[curPos]);
        while (parent[curPos] != curPos) {
            curPos = parent[curPos];
            result.push_back(nums[curPos]);
        } 
        return result;
    }
};