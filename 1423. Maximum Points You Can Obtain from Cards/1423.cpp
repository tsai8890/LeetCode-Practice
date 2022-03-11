#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 1423. Maximum Points You Can Obtain from Cards
    Time Complexity: 
        1. O(k)

    Algorithm:
        1. Two Pointer

    Date: 12/28/2021 16:14							
    Time: 44 ms  -- beat 98.27%
    Memory: 42.3 MB  -- beat 79.28%
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i = 0, j = cardPoints.size() - 1;
        int curScore = 0;
        while (i < k) {
            curScore += cardPoints[i++];   
        }
        i -= 1;
        
        int maxScore = curScore;
        while (i >= 0) {
            curScore += cardPoints[j--];
            curScore -= cardPoints[i--];
            maxScore = max(maxScore, curScore);
        }
        return maxScore;
    }
};