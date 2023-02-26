#include <vector>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> increDP(n, 0);
        vector<int> decreDP(n, 0);

        int total = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (rating[j] < rating[i]) {
                    increDP[i] ++;
                    total += increDP[j];
                }
                if (rating[j] > rating[i]) {
                    decreDP[i] ++;
                    total += decreDP[j];
                }
            }
        }
        return total;
    }
};