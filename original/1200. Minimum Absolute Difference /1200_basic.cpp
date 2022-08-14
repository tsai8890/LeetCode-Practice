#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
    /*
        Title: 1200. Minimum Absolute Difference
        Time Complexity: O(nlogn)

        Algorithm:
            1. Nothing

        Note:
            1. 需要兩次遍歷，一次是找min_diff，一次是把差等於min_diff
               的pair加到result裏面。

        Date: 12/21/2021 11:08				
        Time: 64 ms  -- beat 81.95%
        Memory: 32.5 MB  -- beat 32.32%
    */
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size()-1; i ++) {
            min_diff = min(min_diff, arr[i+1] - arr[i]);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < arr.size()-1; i ++) {
            if (arr[i+1] - arr[i] == min_diff) {
                vector<int> added = {arr[i], arr[i+1]};
                result.push_back(added);
            }
        }
        return result;
    }
};