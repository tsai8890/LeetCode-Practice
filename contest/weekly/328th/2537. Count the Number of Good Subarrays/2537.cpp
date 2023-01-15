#include <unordered_map>
#include <vector>
using namespace std;

/*
    sliding window + hash table
*/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> stat;
        int left = 0, right = -1;
        int pairs = 0;
        long long total = 0;
        while (right < n) {
            right += 1;
            if (stat.find(nums[right]) == stat.end()) {
                stat[nums[right]] = 1;
            }
            else {
                pairs += stat[nums[right]];
                stat[nums[right]] ++;
            }
            
            if (pairs >= k) {
                while (left < right && pairs >= k) {
                    total += (n-right);
                    pairs -= (stat[nums[left]]-1);
                    stat[nums[left]]--;
                    left++;
                }
            }
        }
        
        return total;
    }
};