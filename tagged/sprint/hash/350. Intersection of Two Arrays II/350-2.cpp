#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> count(1001, 0);
        for (auto& num: nums1) {
            count[num] ++;
        }
        
        vector<int> res;
        for (auto& num: nums2) {
            if (count[num] > 0) {
                count[num] --;
                res.push_back(num);
            }
        }
        return res;
    }
};