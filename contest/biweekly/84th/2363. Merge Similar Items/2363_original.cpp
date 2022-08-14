#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> hashMap;
        for (auto& item: items1) {
            if (hashMap.find(item[0]) != hashMap.end()) {
                hashMap[item[0]] += item[1];
            }
            else {
                hashMap[item[0]] = item[1];
            }
        }
        
        for (auto& item: items2) {
            if (hashMap.find(item[0]) != hashMap.end()) {
                hashMap[item[0]] += item[1];
            }
            else {
                hashMap[item[0]] = item[1];
            }
        }
        
        vector<vector<int>> result;
        for (auto p: hashMap) {
            result.push_back(vector<int>{p.first, p.second});
        }
        sort(result.begin(), result.end());
        return result;
    }
};