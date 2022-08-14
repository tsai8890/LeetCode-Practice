class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int x = nums.back();
        
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= x) {
                x = nums[i];
            }
            else {
                int k = (nums[i]+x-1) / x;
                res += k-1;
                x = nums[i] / k;
            }
        }
        return res;
    }
};