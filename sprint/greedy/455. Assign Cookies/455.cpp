#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int n = g.size(), m = s.size();
        int j = 0, total = 0;
        for (int i = 0; i < m; i ++) {
            if (s[i] >= g[j]) {
                j ++;
                total ++;
                if (j == n) {
                    break;
                }
            }  
        }
        return total;
    }
};