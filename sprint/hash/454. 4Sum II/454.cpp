#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> uMap;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int sum = nums1[i]+nums2[j];
                if (uMap.find(sum) == uMap.end()) {
                    uMap[sum] = 0;
                }
                uMap[sum] ++;
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                int target = -(nums3[i]+nums4[j]);
                if (uMap.find(target) != uMap.end()) {
                    count += uMap[target];
                }
            }
        }
        return count;
    }
};