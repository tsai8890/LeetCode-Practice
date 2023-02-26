#include <vector>
#include <unordered_map>
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
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int, int> pos;
        BIT bit(2*m);
        for (int i = 1; i <= m; i ++) {
            pos[i] = i+m;
            bit.addVal(i+m, 1);
        }

        int qSize = queries.size();
        vector<int> res(qSize);
        for (int i = 0; i < qSize; i ++) {
            res[i] = bit.queryRange(pos[queries[i]]-1);
            bit.addVal(pos[queries[i]], -1);
            pos[queries[i]] = m-i;
            bit.addVal(pos[queries[i]], 1);
        }
        return res;
    }
};