#include <vector>
#include <unordered_map>
using namespace std;

/*
    Title: 560. Subarray Sum Equals K
    Time Complexity: 
        1. O(n)
    
    Space Complexity:
        1. O(n)

    Algorithm:
        1. Hashmap

    Note:
        1. 把這題轉換成找prefix_sum array中「後面元素減前面元素==k的pair」的個數
           就可以直接用hashmap做完了。

        2. 如果只是要在dictionary中找存不存在該元素，使用find會比count快很多。

    Date: 01/16/2022 01:17						
    Time: 72 ms  -- beat 82.33%
    Memory: 36.1 MB  -- beat 64.79%
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_count;
        sum_count[0] = 1;
        int total_count = 0;
        
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            cur_sum += nums[i];

            if (sum_count.find(cur_sum - k) != sum_count.end()) {
                total_count += sum_count[cur_sum - k];
            }
            
            if (sum_count.count(cur_sum) == 0)
                sum_count[cur_sum] = 1;
            else 
                sum_count[cur_sum] += 1;
        }
        return total_count;
    }
};