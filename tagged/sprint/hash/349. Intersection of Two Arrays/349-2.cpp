#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> set1(1001, false);
        for (auto& num: nums1) {
            set1[num] = true;
        }
        
        vector<int> res;
        vector<bool> set2(1001, false);
        for (auto& num: nums2) {
            if (set1[num]) {
                if (set2[num] == false) {
                    res.push_back(num);
                    set2[num] = true;
                }
            }
        }
        return res;
    }
};