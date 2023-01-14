#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& p1, const vector<int>& p2) {
        if (p1[1] == p2[1]) {
            return p1[0] <= p2[0];
        }
        return p1[1] <= p2[1];
    }  
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        
        int n = points.size();
        int arrows = 1;
        int end = points[0][1];
        for (auto& point: points) {
            if (point[0] > end) {
                end = point[1];
                arrows ++;
            }
        }
        return arrows;
    }
};