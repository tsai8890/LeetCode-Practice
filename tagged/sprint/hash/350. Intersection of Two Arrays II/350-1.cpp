#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for (auto& num: nums1) {
            if (count.find(num) == count.end()) {
                count[num] = 0;
            }
            count[num] ++;
        }
        
        vector<int> res;
        for (auto& num: nums2) {
            if (count.find(num) != count.end() && count[num] > 0) {
                count[num] --;
                res.push_back(num);
            }
        }
        return res;
    }
};