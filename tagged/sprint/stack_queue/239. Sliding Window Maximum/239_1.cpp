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
        deque<int> posDeque;
        for (int i = 0; i < n; i ++) {
            if (valueDeque.empty()) {
                valueDeque.push_back(nums[i]);
                posDeque.push_back(i);
            }
            else {
                while (!valueDeque.empty() && nums[i] >= valueDeque.back()) {
                    valueDeque.pop_back();
                    posDeque.pop_back();
                }
                valueDeque.push_back(nums[i]);
                posDeque.push_back(i);
            }

            if (i >= k-1) {
                if (i - posDeque.front() + 1 > k) {
                    valueDeque.pop_front();
                    posDeque.pop_front();
                }
                res.push_back(valueDeque.front());
            }
        }
        return res;
    }
};