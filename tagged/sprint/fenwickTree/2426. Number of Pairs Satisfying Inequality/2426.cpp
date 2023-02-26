#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) {
        bit = vector<int>(n+1, 0);
        this->n = n;
    }

    void addVal(int index, int val) {
        index += 20000+1;
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] += val;
        }
    }

    int queryRange(int index) {
        index += 20000+1;
        int sum = 0;
        for (int i = index; i >= 1; i -= (i&-i)) {
            sum += bit[i];
        }
        return sum;
    }

private:
    vector<int> bit;
    int n;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        BIT bit(50000+1);
        long long res = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i ++) {
            res += bit.queryRange(nums1[i]-nums2[i]+diff);
            bit.addVal(nums1[i]-nums2[i], 1);
        }
        return res;
    }
};