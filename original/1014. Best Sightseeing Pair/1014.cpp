#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 1014. Best Sightseeing Pair
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm:
        1. Dynamic Programming        
    
    Note:
        1. max_i_score: values[i] + i 的最大值(for i in 0 to j-1)

    Date: 01/27/2022 17:04			
    Time: 52 ms  -- beat 71.92%
    Memory: 39.3 MB  -- beat 98.66%
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = values[0] + values[1] + 0 - 1;
        int max_i_score = values[0];
        
        for (int j = 1; j < values.size(); j++) {
            maxScore = max(maxScore, max_i_score + values[j] - j);
            max_i_score = max(max_i_score, values[j] + j);
        }
        return maxScore;
    }
};