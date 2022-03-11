#include <vector>
using namespace std;

/*
    Title: 997. Find the Town Judge
    Time Complexity: 
        1. O(n)

    Algorithm:
        1. Brutal force
        
    Date: 01/04/2022 00:41									
    Time: 180 ms  -- beat 48.88%
    Memory: 68.7 MB  -- beat 35.38%
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1, 0);
        vector<bool> trust_nobody(n+1, true);
        
        for (auto item: trust) {
            trusted[item[1]] += 1;
            trust_nobody[item[0]] = false;
        }
        
        for (int i = 1; i <= n; i ++) {
            if (trusted[i] == n-1 && trust_nobody[i])
                return i;
        }
        return -1;
    }
};