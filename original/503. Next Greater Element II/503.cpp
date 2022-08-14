#include <vector>
#include <stack>
using namespace std;

/*
    Title: 503. Next Greater Element II
    Time Complexity: O(n)
    Algorithm:
        1. Monotonic stack

    Note:
        1. 如果題目要求是circular array，有很大機率可以透過
           直接複製一遍array來解決!!
        
        2. 有點難直接想到要用stack...，還需要多練練
            
    Date: 01/05/2022 21:55						
    Time: 32 ms  -- beat 74.79%
    Memory: 25.5 MB  -- beat 11.11%
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> double_nums = nums;
        for (auto num : nums) {
            double_nums.push_back(num);
        }
        
        stack<int> st;
        vector<int> res(nums.size(), -1);
        
        for (int i = double_nums.size() - 1; i >= 0; i --) {
            while (!st.empty() && double_nums[i] >= st.top()) {
                st.pop(); 
            }
            
            if (i < nums.size()) {
                if (st.empty())
                    res[i] = -1;
                else
                    res[i] = st.top();
            }    
            st.push(double_nums[i]);
        }
        return res;
    }
};