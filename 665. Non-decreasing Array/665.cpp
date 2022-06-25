#include <vector>
using namespace std;

/*
    Title: 665. Non-decreasing Array
    Time Complexity: O(n)
    Space Complexity: O(1) - extra space

    Algorithm: 
        1. Nothing, just logics
        
    Note:
        1.  這題 brutal force 的解法需要 O(n^2)-time，
            需要以 O(n)-time 遍歷 nums[0..n-1] 中可能的調整點 ，
            檢查每個調整點是否符合條件需要 O(n)-time 來檢查調整點左右的序列
            所以需要 O(n^2)-time

            然而，可以先找出所有 non-decreasing subsequences，
            並且可以分成 3 個 case
            i.      只有一個，代表不需要調整
                        回傳 true
            
            ii.     三個或三個以上，代表使用一次調整一定調整不完
                        回傳 false
            
            iii.    剛好兩個，則才需要討論
                    令兩個 subsequence 為 [nums[0]..nums[i], [nums[i+1]..nums[n-1]]

                    a.  若有任一個 subsequence 長度 <= 1，代表該 subsequence 一定可以一次調整完
                        回傳 true

                    b.  若沒有，則可以確定可能的調整點只有 
                        第一個 subsequence 的結尾 或 第二個 subsequence 的開頭
                        因為調整其他地方不會改善整體的 non-decreasing

                        且兩個 subsequence 都是 non-decreasing
                        因此
                            i.  若選第一個 subsequence 的結尾當調整點
                                只需檢查 nums[i-1] <= nums[i+1]

                            ii. 若選第二個 subsequence 的開頭當調整點
                                只需檢查 nums[i] <= nums[i+2]

                        以上兩項有任一項符合即回傳 true
                        否則回傳 false

        2.  Total Time Complexity = O(n)
            Total Space Complexity = O(1)
    
    Date: 06/26/2022 02:45																			    			
    Time: 26 ms  -- beat 94.77%
    Memory: 27 MB  -- beat 81.98%
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return true;
        }
        
        int reverse_count = 0, reverse_point = -1;
        for (int i = 1; i < n; i ++) {
            if (nums[i] < nums[i-1]) {
                reverse_point = i-1;
                reverse_count += 1;
                if (reverse_count >= 2) {
                    break;
                }
            }
        }
        
        if (reverse_count == 0) {
            return true;
        }
        else if (reverse_count == 1) {
            if (reverse_point == 0 || reverse_point == n-2) {
                return true;
            }
            else {
                return (nums[reverse_point-1] <= nums[reverse_point+1] ||
                        nums[reverse_point] <= nums[reverse_point+2]);
            }
        }
        else {
            return false;
        }
    }
};