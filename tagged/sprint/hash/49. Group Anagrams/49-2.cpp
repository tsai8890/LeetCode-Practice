#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (int i = 0; i < strs.size(); i ++) {
            vector<int> cnt(26, 0);
            for (auto& c: strs[i]) {
                cnt[c-(int)('a')] += 1;
            }
            
            string hashStr;
            for (int i = 0; i < 26; i ++) {
                if (cnt[i] != 0) {
                    hashStr += to_string('a'+i);
                    hashStr += to_string(cnt[i]);
                }
            }

            if (groups.find(hashStr) == groups.end()) {
                groups[hashStr] = vector<string>();
            }
            groups[hashStr].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for (auto& group: groups) {
            res.push_back(group.second);
        }
        return res;
    }
};