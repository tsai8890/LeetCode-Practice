#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
        Time Complexity:
            1. O(n)

        Note:
            1. Dynamically maintain a max_4 vector and a min_4 vector.

        Date: 12/17/2021 19:03							
        Time: 76ms  -- beat 95.20%
        Memory: 35.2 MB  -- beat 49.55%
    */
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        } else {
            vector<int> max_4;
            vector<int> min_4;
            
            for (int i = 0; i < 4; i ++) {
                max_4.push_back(nums[i]);
                min_4.push_back(nums[i]);
            }
            sort(max_4.begin(), max_4.end());
            reverse(max_4.begin(), max_4.end());
            sort(min_4.begin(), min_4.end());
            
            for (int i = 4; i < nums.size(); i ++) {
                int j;

                for (j = 3; j >= 0; j --) {
                    if (nums[i] <= max_4[j]) 
                        break;
                }
                if (j < 3) {
                    for (int k = 3; k > j + 1; k --) 
                        max_4[k] = max_4[k-1];
                    max_4[j + 1] = nums[i];
                }
                
                for (j = 3; j >= 0; j --) {
                    if (nums[i] >= min_4[j]) 
                        break;
                }
                if (j < 3) {
                    for (int k = 3; k > j + 1; k --) 
                        min_4[k] = min_4[k-1];
                    min_4[j + 1] = nums[i];
                }
            }
            
            int most_far = max_4[0] - min_4[0];
            int max_decrease = 0;
            for (int i = 0; i <= 3; i ++) {
                int decrease = min_4[i] - min_4[0];
                decrease += max_4[0] - max_4[3-i];
                max_decrease = max(max_decrease, decrease);
            }
            return most_far - max_decrease;
        }
    }
};