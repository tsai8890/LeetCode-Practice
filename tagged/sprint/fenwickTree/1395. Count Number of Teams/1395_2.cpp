#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree() {
        n = 100000;
        bit = vector<int>(n+1, 0);
    }

    void addVal(int index, int val) {
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] += val;
        }
    }

    int queryRange(int index) {
        if (index == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = index; i >= 1; i -= (i&-i)) {
            sum += bit[i];
        }
        return sum;
    }

    int getTotal() {
        return queryRange(n);
    }

private:
    long long n;
    vector<int> bit;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        BIT increBIT, decreBIT;
        BIT statBIT;

        int total = 0;
        for (int i = 0; i < n; i ++) {
            if (i >= 2) {
                total += increBIT.queryRange(rating[i]-1);
                total += decreBIT.getTotal() - decreBIT.queryRange(rating[i]);
            }
            if (i >= 1) {
                int increCount = statBIT.queryRange(rating[i]-1);
                int decreCount = statBIT.getTotal() - statBIT.queryRange(rating[i]);
                increBIT.addVal(rating[i], increCount);
                decreBIT.addVal(rating[i], decreCount);
            }
            statBIT.addVal(rating[i], 1);
        }
        return total;
    }
};