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

private:
    vector<int> bit;
    int n;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> before(n, 0);
        vector<int> after(n, 0);
        BIT beforeBIT(100000);
        BIT afterBIT(100000);

        for (int i = 0; i < n; i ++) {
            before[i] = beforeBIT.queryRange(nums[i]-1);
            beforeBIT.addVal(nums[i], 1);
        }
        for (int i = n-1; i >= 0; i --) {
            after[i] = afterBIT.queryRange(nums[i]-1);
            afterBIT.addVal(nums[i], 1);
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (before[i] >= k && after[i] >= k) {
                res ++;
            }
        }
        return res;
    }
};