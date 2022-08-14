#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 45. Jump Game II
    Time Complexity: O(n)
    Space Complexity: O(1)

    Algorithm:
        1. Greedy

    Note: 
        1. 這題最快的是用貪婪演算法。
           若現在在i的位置，則下一步選擇一個 j for j in [i+1, i+nums[i]]， 
           使得j+nums[j]最大(即從j可以跳到最遠)，這個結果是local optimal，一定也是global optimal。

           proof:
              可以利用proof by contradiction。 
        
        2. 真的有點通靈...，寫過把它記起來吧

    Date: 01/30/2022 22:39						
    Time: 8 ms  -- beat 98.77%
    Memory: 16.6 MB  -- beat 41.11%
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = -1, right_end = 0;
        int farthest = 0;
        int total_steps = 0;
        
        int n = nums.size();
        while (right_end < n - 1) {
            int j = cur + 1;
            while (j <= right_end) {
                if (nums[j] + j > nums[farthest] + farthest) {
                    farthest = j;
                }
                j += 1;                
            }
            
            cur = farthest;
            right_end = cur + nums[cur];
            total_steps += 1;
        }
        return total_steps;
    }
};
