#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) {
        bit = vector<int>(n+1, 0);
        this->n = n;
    }

    void addVal(int index, int val) {
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] += val;
        }
    }

    int queryRange(int index) {
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
    vector<int> bit;
    int n;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        BIT bit(100000);
        int total = 0;
        int n = instructions.size();
        for (int i = 0; i < n; i ++) {
            int target = instructions[i];
            total += min(bit.queryRange(target-1),
                        bit.getTotal() - bit.queryRange(target));
            total = total % 1000000007;
            bit.addVal(instructions[i], 1);
        }
        return total;
    }
};