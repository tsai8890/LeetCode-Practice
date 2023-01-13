#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        for (auto& num: nums1) {
            set1.insert(num);
        }
        
        vector<int> res;
        unordered_set<int> set2;
        for (auto& num: nums2) {
            if (set1.count(num) == 1) {
                set2.insert(num);
            }
        }
        
        vector<int> res;
        for (auto& num: set2) {
            res.push_back(num);
        }
        return res;
    }
};