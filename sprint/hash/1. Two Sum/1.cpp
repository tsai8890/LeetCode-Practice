#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uMap;
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (uMap.find(target-nums[i]) != uMap.end()) {
                return vector<int>{uMap[target-nums[i]], i};
            }
            uMap[nums[i]] = i;
        }
        return vector<int>();
    }
};