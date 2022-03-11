#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 973. K Closest Points to Origin
        Time Complexity: O(nlogn)
        Algorithm:
            1. Sorting

        Note:
            1. 可以使用quick select，平均複雜度更低
                
        Date: 12/26/2021 18:46							
        Time: 168 ms  -- beat 66.08%
        Memory: 51.9 MB  -- beat 77.22%
    */
public:
    static bool compare(vector<int>& A, vector<int>& B) {
        return ((A[0]*A[0] + A[1]*A[1]) < (B[0]*B[0] + B[1]*B[1]));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare);
            
        vector<vector<int>> result;
        for (int i = 0; i < k; i ++) {
            result.push_back(points[i]);
        }
        return result;
    }
};