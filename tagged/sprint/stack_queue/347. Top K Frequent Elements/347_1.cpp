#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> stats;
        for (int num: nums) {
            if (stats.find(num) != stats.end()) {
                stats[num] += 1;
            }
            else {
                stats[num] = 1;
            }
        }

        class Compare {
        public:
            bool operator() (const vector<int>& lfs, const vector<int>& rfs) {
                return lfs[0] >= rfs[0];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for (pair<int, int> e: stats) {
            vector<int> v = {e.second, e.first};
            pq.push(v);

            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};