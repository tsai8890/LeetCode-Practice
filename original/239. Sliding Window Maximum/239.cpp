#include <vector>
#include <deque>
using namespace std;

/*
    Title: 239. Sliding Window Maximum
    Time Complexity: 
        1. O(n)

    Algorithm:
        1. Monotonic Queue(單調隊列)

    Note:
        1. 這題很經典，直接用單調隊列解就可以了
        2. 單調隊列教學:
            https://oi-wiki.org/ds/monotonous-queue/
            
    Date: 01/05/2022 20:48							
    Time: 232 ms  -- beat 87.68%
    Memory: 131.9 MB  -- beat 49.54%
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (i >= k) {
                if (nums[i-k] == dq.front()) 
                    dq.pop_front();
            }
           
            while (!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            
            if (i >= k - 1) {
                res.push_back(dq.front());
            }
        }
        return res;
    }
};