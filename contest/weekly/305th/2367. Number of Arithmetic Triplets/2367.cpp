class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n-2; i ++) {
            unordered_map<int, int> hash;
            for (int j = i+1; j < n; j ++) {
                if (nums[i] + diff*2 == nums[j]) {
                    int mid = nums[i] + diff;
                    if (hash.find(mid) != hash.end()) {
                        count += hash[mid];
                    }
                }
                if (hash.find(nums[j]) != hash.end()) {
                    hash[nums[j]] += 1;
                }
                else {
                    hash[nums[j]] = 1;
                }
            }
        }
        return count;
    }
};