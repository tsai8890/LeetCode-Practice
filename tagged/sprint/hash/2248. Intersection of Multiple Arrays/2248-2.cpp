#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> count(1001, 0);
        for (auto& numArr: nums) {
            for (auto& num: numArr) {
                count[num] ++;
            }
        }

        int n = nums.size();
        vector<int> res;
        for (auto& num: nums.back()) {
            if (count[num] == n) {
                res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};