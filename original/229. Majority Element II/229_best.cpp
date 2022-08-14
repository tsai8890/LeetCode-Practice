#include <vector>
using namespace std;

/*
    Title: 229. Majority Element II
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
        1. Moore's Voting Algorithm        
    
    Note:
        1.  若nums裡面有majority element(數量超過size/3)，
            則將nums裡面三個不一樣的元素刪除，
            修改後的nums的majority element不會改變。

        2.  使用maj1, maj2, cnt1, cnt2來儲存目前看到的兩種元素以及其個數，
            當出現與maj1, maj2都不同的元素，就三個一組把它消掉。
        
    Date: 01/15/2022 22:34		
    Time: 12 ms  -- beat 78.40%
    Memory: 15.9 MB  -- beat 50.66%
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1, maj2;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (cnt1 != 0 && nums[i] == maj1) {
                cnt1 += 1;
            }
            else if (cnt2 != 0 && nums[i] == maj2) {
                cnt2 += 1;
            }
            else {
                if (cnt1 == 0) {
                    cnt1 = 1;
                    maj1 = nums[i];
                }
                else if (cnt2 == 0) {
                    cnt2 = 1;
                    maj2 = nums[i];
                }
                else {
                    cnt1 -= 1;
                    cnt2 -= 1;
                }
            }
        }
        
        // Check if the result is correct
        int test_cnt1 = 0, test_cnt2 = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == maj1) {
                test_cnt1 += 1;
            }
            else if (nums[i] == maj2) {
                test_cnt2 += 1;
            }
        }
        
        vector<int> result;
        if (test_cnt1 >= nums.size()/3 + 1) { 
            result.push_back(maj1);
        }
        if (test_cnt2 >= nums.size()/3 + 1) {
            result.push_back(maj2);
        }
        return result;
    }
};