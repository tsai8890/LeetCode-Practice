#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    Title: 525. Contiguous Array
    Time Complexity: O(n)
    Space Complexity: O(n)

    Algorithm:
        1. Dynamic Programming
        2. Hash Table

    Note: 
        1. Definition: V(i): (# of ones - # of zeros) in nums[0..i]
           所以，任何符合條件的subarray，nums[i..j]，一定滿足V(j) - V[i-1] = 0

           因此，可以使用hash table，將沿途碰到的 (V(i), i)-pair 記錄起來(只記錄最早出現的)，
           這樣每當在查看以nums[j]為結尾的、符合條件的subarray時，只需要檢查hash_table[V[j]]即可。
                i.  若裡面沒有V[j]的key，就把(V[j],j)-pair加入到hash_table裡面。
                ii. 若已經存在V[j]的key，j-hash_table[V[j]]就是以nums[j]結尾的最長subarray長度，
                    使用它來更新maxLen。
                    
        2. 這題很巧，把它記起來

    Date: 02/05/2022 16:37									
    Time: 147 ms  -- beat 59.72%
    Memory: 83.7 MB  -- beat 86.89%
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> hash_t;
        hash_t[0] = -1;

        int curSum = 0, maxLen = 0;
        for (int i = 0; i < n; i ++) {
            curSum = (nums[i] == 0) ? curSum - 1 : curSum + 1;

            if (hash_t.find(curSum) != hash_t.end()) {
                maxLen = max(maxLen, i - hash_t[curSum]);
            }
            else {
                hash_t[curSum] = i;
            }
        }
        return maxLen;
    }
};