#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Priority Queue

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        long long sum = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < n; i ++) {
            pq.push(gifts[i]);
            sum += gifts[i];
        }

        for (int i = 0; i < k; i ++) {
            int maxVal = pq.top();
            pq.pop();
            sum -= (maxVal - sqrt(maxVal));
            pq.push(sqrt(maxVal));
        }
        return sum;
    }
};