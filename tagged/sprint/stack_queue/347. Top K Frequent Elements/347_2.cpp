#include <vector>
#include <unordered_map>
#include <queue>

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
            bool operator() (const pair<int, int>& lfs, const pair<int, int>& rfs) {
                return lfs.second >= rfs.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (pair<int, int> e: stats) {
            pq.push(e);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};