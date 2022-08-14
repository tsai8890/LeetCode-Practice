#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if (n < k) {
            return res;
        }

        deque<int> valueDeque;
        for (int i = 0; i < n; i ++) {
            if (valueDeque.empty()) {
                valueDeque.push_back(nums[i]);
            }
            else {
                while (!valueDeque.empty() && nums[i] > valueDeque.back()) {
                    valueDeque.pop_back();
                }
                valueDeque.push_back(nums[i]);
            }

            if (i >= k-1) {
                if (i >= k && nums[i-k] == valueDeque.front()) {
                    valueDeque.pop_front();
                }
                res.push_back(valueDeque.front());
            }
        }
        return res;
    }
};