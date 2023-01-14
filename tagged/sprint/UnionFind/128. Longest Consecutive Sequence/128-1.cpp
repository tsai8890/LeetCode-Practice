#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int find(unordered_map<int, pair<int, int>>& dsjSet, int i) {
        if (dsjSet[i].first != i) {
            dsjSet[i].first = find(dsjSet, dsjSet[i].first);
        }
        return dsjSet[i].first;
    }
    
    bool Union(unordered_map<int, pair<int, int>>& dsjSet, int i, int j, int& maxLen) {
        int set_i = find(dsjSet, i);
        int set_j = find(dsjSet, j);
        if (set_i == set_j) {
            return false;
        }
        
        if (dsjSet[set_i].second > dsjSet[set_j].second) {
            dsjSet[set_j].first = set_i;
            dsjSet[set_i].second += dsjSet[set_j].second;
            maxLen = max(maxLen, dsjSet[set_i].second);
        }
        else {
            dsjSet[set_i].first = set_j;
            dsjSet[set_j].second += dsjSet[set_i].second;
            maxLen = max(maxLen, dsjSet[set_j].second);
        }
        return true;
    }
    
    void makeSet(unordered_map<int, pair<int, int>>& dsjSet, int i) {
        dsjSet[i].first = i;
        dsjSet[i].second = 1;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        unordered_map<int, pair<int, int>> dsjSet;
        int maxLen = 1;
        for (auto num: nums) {
            if (dsjSet.find(num) != dsjSet.end()) {
                continue;
            }
            
            makeSet(dsjSet, num);
            if (dsjSet.find(num+1) != dsjSet.end()) {
                Union(dsjSet, num, num+1, maxLen);
            }
            if (dsjSet.find(num-1) != dsjSet.end()) {
                Union(dsjSet, num, num-1, maxLen);
            }
        }
        return maxLen;
    }
};