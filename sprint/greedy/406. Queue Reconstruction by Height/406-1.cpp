#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0]) {
            return v1[1] <= v2[1];
        }
        else {
            return v1[0] > v2[0];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        
        int n = people.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i ++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};