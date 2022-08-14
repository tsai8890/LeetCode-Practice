class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> longest(26, 0);
        for (int i = 0; i < n; i++) {
            int maxVal = 0;
            for (int j = -k; j <= k; j ++) {
                int key = s[i]-'a'+j;
                if (key >= 0 && key < 26) {
                    maxVal = max(maxVal, longest[key]);
                }
            }
            longest[s[i]-'a'] = max(longest[s[i]-'a'], maxVal+1);
        }
        
        int maxVal = 0;
        for (int i = 0; i < 26; i ++) {
            maxVal = max(maxVal, longest[i]);
        }
        return maxVal;
    }
};