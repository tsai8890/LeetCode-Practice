#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0, digitSum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            int j = nums[i];
            while (j > 0) {
                digitSum += j % 10;
                j = j / 10;
            }
        }
        return abs(sum - digitSum);
    }
};