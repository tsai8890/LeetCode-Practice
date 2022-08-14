#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashMap;
        long long count = 0;

        for (int i = 0; i < n; i ++) {
            int key = nums[i] - i; 
            count += i - hashMap[key];
            
            if (hashMap.find(key) == hashMap.end()) {
                hashMap[key] = 1;
            }
            else {
                hashMap[key] += 1;
            }
        }
        return count;
    }
};