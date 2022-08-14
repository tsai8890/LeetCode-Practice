#include <vector>
#include <iostream>
using namespace std;

/*
    Title: 169. Majority Element

    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
        1. Moore's Voting Algorithm        
    
    Note:
        1. 若nums裡面有majority element(數量超過size/2)，
            則將nums裡面任兩個不一樣的元素刪除，
            修改後的nums的majority element不會改變。
        
    Date: 01/15/2022 21:29		
    Time: 16 ms  -- beat 85.37%
    Memory: 19.7 MB  -- beat 8.64%
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int repeat = nums[0];
        int cnt = 1;

        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == repeat) {
                cnt += 1;
            } 
            else {
                if (cnt == 0) {
                    repeat = nums[i];
                    cnt = 1;
                }
                else {
                    cnt -= 1;
                }
            }
        }
        
        // Check if the result is the majority element
        cnt = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (repeat == nums[i])
                cnt += 1;
        }

        if (cnt >= (nums.size()+1)/2)
            return repeat;
        else 
            return -1;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 2, 3, 3, 3};
    cout << sol.majorityElement(nums) << endl;
}