#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 264. Ugly Number II
    Time Complexity: 
        1. O(nlogn)

    Algorithm:
        1. Brutal Force
    
    Note:
        1. 直接暴力找出[1..INT_MAX]的所有ugly numbers，剛好是1690個
        2. 找完後再sort，即可找出答案
        
    Date: 01/03/2022 21:37										
    Time: 0 ms  -- beat 100.00%
    Memory: 6.2 MB  -- beat 81.03%
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> nums;
        if (nums.empty()) {
            for (long long int a = 1; a <= INT_MAX; a *= 2) {
                for (long long int b = a; b <= INT_MAX; b *= 3) {
                    for (long long int c = b; c <= INT_MAX; c *= 5) {
                        nums.push_back(c);
                    }
                }
            }
            sort(nums.begin(), nums.end());
        }
        return nums[n-1];
    }
};