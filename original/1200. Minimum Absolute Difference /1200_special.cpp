#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    /*
        Title: 1200. Minimum Absolute Difference
        Time Complexity: O(n)

        Algorithm:
            1. Counting Sort

        Note:
            1. Counting Sort 學起來

        Date: 12/21/2021 13:08		
        Time: 100 ms  -- beat 17.2%
        Memory: 53.4 MB  -- beat 5.25%
    */
public:
    vector<int> counting_sort(vector<int> nums, int min_, int max_) {
        vector<int> count(max_ - min_ + 1, 0);

        for (int i = 0; i < nums.size(); i ++) {
            count[nums[i] - min_] += 1;
        }
        for (int i = min_ + 1; i <= max_; i ++) {
            count[i - min_] = count[i - min_] + count[i - min_ - 1];
        }

        vector<int> result(nums.size());
        for (int i = nums.size() - 1; i >= 0; i --) {
            result[count[nums[i] - min_] - 1] = nums[i];
            count[nums[i] - min_] -= 1;
        }
        return result;
    }
    
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_ = INT_MAX, max_ = INT_MIN;
        for (int i = 0; i < arr.size(); i ++) {
            min_ = min(min_, arr[i]);
            max_ = max(max_, arr[i]);
        }
        arr = counting_sort(arr, min_, max_);
        
        vector<vector<int>> result;
        int min_diff = 100000000;
        for (int i = 0; i < arr.size()-1; i ++) {
            if (arr[i+1] - arr[i] == min_diff) {
                vector<int> added = {arr[i], arr[i+1]};
                result.push_back(added);
            } 
            else if (arr[i+1] - arr[i] < min_diff) {
                result.clear();
                vector<int> added = {arr[i], arr[i+1]};
                result.push_back(added);
                min_diff = arr[i+1] - arr[i];
            }
        }
        return result;
    }
};