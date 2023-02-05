#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Greedy

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> stat;
        for (int i = 0; i < basket1.size(); i ++) {
            stat[basket1[i]] ++;
            stat[basket2[i]] --;
        }
        
        vector<int> toSwap;
        for (auto p: stat) {
            if (p.second % 2) {
                return -1;
            }
            for (int i = 0; i < abs(p.second)/2; i ++) {
                toSwap.push_back(p.first);
            }
        }

        long long cost = 0;
        int minX = min(*min_element(basket1.begin(), basket1.end()),
                    *min_element(basket2.begin(), basket2.end()));
        nth_element(toSwap.begin(), toSwap.begin() + toSwap.size()/2, toSwap.end());
        for (int i = 0; i < toSwap.size()/2; i ++) {
            cost += min(2*minX, toSwap[i]);
        }
        return cost;
    }
};