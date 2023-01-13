#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        int n = s.length();
        for (int i = 0; i < n; i ++) {
            last[s[i]-'a'] = i;
        }
        
        int lastPos = 0;
        int rightMost = -1;
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            rightMost = max(rightMost, last[s[i]-'a']);
            if (i == rightMost) {
                res.push_back(i-lastPos+1);
                lastPos = i+1;
            }
        }
        return res;
    }
};