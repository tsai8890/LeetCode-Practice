#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        int sum = n;
        for (int i = 1; i < n; i ++) {
            if (ratings[i] > ratings[i-1]) {
                sum += (candies[i-1] + 1) - candies[i];
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = n-2; i >= 0; i --) {
            if (ratings[i] > ratings[i+1]) {
                int after = max(candies[i], candies[i+1] + 1);
                sum += after - candies[i];
                candies[i] = after;
            }
        }
        return sum;
    }
};