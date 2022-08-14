#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 396. Rotate Function
    Time Complexity: O(3xn)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1.  如果 brutal force 的話，需要 O(n^2)-time，因為有 n 種旋轉的情況，
            每種都需要 O(n)-time 去計算 F function。

            但是其實只需要計算尚未旋轉(以nums[n-1]為結尾)時的 F score (即 F(0))，
            再搭配 sum(nums)，即可每次都以 O(1)-time 計算出下一個旋轉後的 F score

            Transition Function:
                F(k) = F(k-1) + sum(nums) - n * nums[n-k]
                where 1 <= k <= n-1

            如此一來，只需要 O(n)xO(1)-time 即可算出所有 n 種 F score。

        2.  Total Time Complexity: O(n)
                O(n) + O(n) + O(n)xO(1) = O(n)

            Total Space Complexity: O(1)

    Date: 06/23/2022 22:38															    			
    Time: 140 ms  -- beat 99.07%
    Memory: 95.8 MB  -- beat 92.30%
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
        }
        
        int F = 0;
        for (int i = 0; i < n; i ++) {
            F += i * nums[i];
        }

        int max_F = F;
        for (int i = n-2; i >= 0; i --) {
            F += sum - n * nums[i+1];
            max_F = max(max_F, F);
        }
        return max_F;
    }
};