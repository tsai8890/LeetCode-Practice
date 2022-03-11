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
            1. 原本要兩次遍歷，一次是找min_diff，一次是把差等於min_diff
               的pair加到result裏面。

            2. 這個解法只需要一次遍歷，同時更新min_diff跟result。

        Date: 12/21/2021 11:02			
        Time: 60 ms  -- beat 93.49%
        Memory: 32.8 MB  -- beat 27.91%
    */
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        
        vector<vector<int>> result;
        for (int i = 0; i < arr.size()-1; i ++) {
            if (arr[i+1] - arr[i] == min_diff) {
                vector<int> added = {arr[i], arr[i+1]};
                result.push_back(added);
                
            } else if (arr[i+1] - arr[i] < min_diff) {
                result.clear();
                vector<int> added = {arr[i], arr[i+1]};
                result.push_back(added);
                min_diff = arr[i+1] - arr[i];
            }
        }
        return result;
    }
};