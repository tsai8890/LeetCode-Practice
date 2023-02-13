#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m*n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (count(m, n, mid) >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    int count(int m, int n, int target) {
        int total = 0;
        for (int i = 1; i <= m; i ++) {
            total += min(n, target / i);
        }
        return total;
    }
};