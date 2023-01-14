#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (int i = 0; i < strs.size(); i ++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            // if (groups.find(str) == groups.end()) {
            //     groups[str] = vector<string>();
            // }
            groups[str].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for (auto& group: groups) {
            res.push_back(group.second);
        }
        return res;
    }
};