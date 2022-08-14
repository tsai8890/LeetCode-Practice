#include <vector>
using namespace std;

/*
    Title: 376. Wiggle Subsequence
    Time Complexity: O(n)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Problem Reduction
        
    Note:
        1. 這題可以 reduce 成 "Peak Counting Problem"

            Peak Counting Problem:
                Given an array of numbers, count the total numbers of min / max peak.

            可以分別從兩個方向證明
            i.  如果找到最長的 wiggle subsequence，則該 wiggle subsequence 的長度 = number of peaks
            ii. 如果總共有 n 個 min / max peaks，則最長的 wiggle subsequence 的長度 = n
            Hint: 反證法
        
        2. Reduce 成 "Peak Counting Problem" 後，其實還是有些 edge case 要處理。

            Raw Idea: 把 array 遍歷一次，找「左小右小 or 左大右大」的 element。
                Issue1: 最左邊和最右邊的元素會有 edge case
                Issue2: 會少算重複的 peak，ex: [2, 3, 3, 2, 4]，會少算第二個 3
           
            我的寫法: 
                i.   使用 cur_dir 來記錄先前的方向(+: 不嚴格遞增, -: 不嚴格遞減)
                
                ii.  把前面幾個和 nums[0] 一樣的元素排除掉，在這一步可以順便檢查是不是全部元素都一樣，
                     如果都一樣，就回傳1
                
                iii. 只遍歷 nums[start..n-2] (start是第一個與nums[0]的值不同的位置)，
                     過程中針對每個 nums[i] 計算下一個方向 (nums[i+1]-nums[i])。
                     如果 cur_dir * 下一個方向(nums[i+1]-nums[i]) < 0，
                     則 nPeaks += 1，且更新 cur_dir (代表進入一個新的方向)
                
                iv.  最後結果要加上 2，因為沒有算到 nums[0] & nums[n-1]，他們兩個也是 peak。
        
        3. 時間複雜度是 O(n)，線性時間。
           空間複雜度是 O(1)。

    Date: 06/05/2022 03:26																	    			
    Time: 0 ms  -- beat 100.00%
    Memory: 6.9 MB  -- beat 95.66%
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        while (start < n && nums[start] == nums[0]) {
            start += 1;
        }
        
        if (start <= n-1) {
            int nPeaks = 2;
            int cur_dir = nums[start] - nums[start-1];
            for (int i = start; i < n-1; i ++) {
                int diff = nums[i+1] - nums[i];
                if ((cur_dir < 0 && diff > 0) || (cur_dir > 0 && diff < 0)) {
                    nPeaks += 1;
                    cur_dir = diff;
                }
            } 
            return nPeaks;
        }
        else {
            return 1;
        }
    }
};