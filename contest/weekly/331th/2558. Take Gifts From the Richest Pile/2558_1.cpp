#include <vector>
#include <cmath>
using namespace std;

// Brute Force

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for (int i = 0; i < k; i ++) {
            int maxPos = 0;
            for (int j = 1; j < n; j ++) {
                if (gifts[maxPos] < gifts[j]) {
                    maxPos = j;
                }
            }
            gifts[maxPos] = sqrt(gifts[maxPos]);
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += gifts[i];
        }
        return sum;
    }
};