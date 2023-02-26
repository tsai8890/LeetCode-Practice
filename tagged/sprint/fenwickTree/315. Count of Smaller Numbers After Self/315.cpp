#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(vector<int>& nums) {
        this->n = 20000+1;
        this->bit = vector<int>(n+1, 0);
    }

    void update(int index, int add) {
        index += 10000 + 1;
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] += add;
        }
    }

    int query(int index) {
        index += 10000 + 1;
        int sum = 0;
        for (int i = index; i >= 1; i -= (i&-i)) {
            sum += bit[i];
        }
        return sum;
    }

private:
    int n;
    vector<int> bit;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BIT bit(nums);

        int n = nums.size();
        vector<int> res(n);
        for (int i = n-1; i >= 0; i--) {
            res[i] = bit.query(nums[i]-1);
            bit.update(nums[i], 1);
        }
        return res;
    }
};