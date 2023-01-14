#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int incre = 1, decre = 1;
        
        for (int i = 1; i < n; i ++) {
            if (nums[i] > nums[i-1]) {
                incre = decre + 1;
            }
            else if (nums[i] < nums[i-1]) {
                decre = incre + 1;
            }
        }
        return max(incre, decre);
    }
};