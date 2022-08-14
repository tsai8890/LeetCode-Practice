#include <vector>
using namespace std;

/*
    Title: 376. Wiggle Subsequence
    Time Complexity: O(n)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        2. Greedy
        
    Note:
        1.  Dynamic Programming (與先前的 dp array 定義不同):
            up[i]:   可以使用nums[0..i]，且最後一個元素是 wiggle up 的最長 wiggle subsequence 的長度
            down[i]: 可以使用nums[0..i]，且最後一個元素是 wiggle down 的最長 wiggle subsequence 的長度

            DP Transition
                i.  nums[i-1] < nums[i]
                        up[i] = down[i-1] + 1
                        down[i] = down[i-1]
                
                ii. nums[i-1] > nums[i]
                        up[i] = up[i-1]
                        down[i] = up[i-1] + 1

                iii. nums[i-1] = nums[i]
                        up[i] = up[i-1]
                        down[i] = down[i-1]
            
            證明寫在 376. Wiggle Subsequence / 376_dp_linear.cpp，有興趣可以去看一下

        2.  因為實際用到的空間只有 O(1 rows x 2 columns)，可以直接用兩個變數 up, down 儲存 
            讓空間複雜度降到 O(1)。

        3.  時間複雜度是 O(n)，線性時間。
            空間複雜度是 O(1)。

    Date: 06/06/2022 21:54																		    			
    Time: 0 ms  -- beat 100.00%
    Memory: 7 MB  -- beat 74.89%
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int up = 1, down = 1;
        
        for (int i = 1; i < n; i ++) {
            if (nums[i-1] < nums[i]) {
                up = down + 1;
            }
            else if (nums[i-1] > nums[i]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};