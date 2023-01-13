#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> front(26, 0);
        vector<int> back(26, 0);
        for (auto ch: s) {
            back[ch-'a'] ++;
        }
        
        int n = s.length();
        int lastPos = 0;
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            front[s[i]-'a'] ++;
            back[s[i]-'a'] --;
            
            bool valid = true;
            for (int j = 0; j < 26; j ++) {
                if (front[j] != 0 && back[j] != 0) {
                    valid = false;
                }                    
            }
            
            if (valid) {
                res.push_back(i-lastPos+1);
                lastPos = i+1;
            }
        }
        return res;
    }
};