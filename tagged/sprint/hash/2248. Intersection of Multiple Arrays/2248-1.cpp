#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> count;
        for (auto& numArr: nums) {
            for (auto& num: numArr) {
                if (count.find(num) == count.end()) {
                    count[num] = 0;
                }
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
        sort(res.begin(), res.end(), less<int>());
        return res;
    }
};