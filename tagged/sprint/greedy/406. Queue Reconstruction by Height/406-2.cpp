#include <vector>
#include <list>
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
        list<vector<int>> linkedList;

        for (int i = 0; i < n; i ++) {
            auto it = linkedList.begin();
            int tmp = people[i][1];
            while (tmp > 0) {
                it ++;
                tmp --;
            }
            linkedList.insert(it, people[i]);
        }
        return vector<vector<int>>(linkedList.begin(), linkedList.end());
    }
};