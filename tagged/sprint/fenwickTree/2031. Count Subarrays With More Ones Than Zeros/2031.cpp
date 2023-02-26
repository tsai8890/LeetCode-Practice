#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int n) {
        this->n = n;
        this->bit = vector<int>(n+1, 0);
    }

    void addVal(int index, int val) {
        index += 100000 + 1;
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] = (bit[i] + val) % 1000000007;
        }
    }

    int prefixSum(int index) {
        index += 100000 + 1;
        int sum = 0;
        for (int i = index; i >= 1; i -= (i&-i)) {
            sum = (sum + bit[i]) % 1000000007;
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
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        BIT bit = BIT(200001);
        
        preSum[0] = (nums[0] == 1) ? 1 : -1;
        for (int i = 1; i < n; i ++) {
            preSum[i] = preSum[i-1] + ((nums[i] == 1) ? 1 : -1);
        }

        int res = 0;
        for (int i = 0; i < n; i ++) {
            if (preSum[i] > 0) {
                res ++;
            }
            res = (res + bit.prefixSum(preSum[i]-1)) % 1000000007;
            bit.addVal(preSum[i], 1);
        }
        return res;
    }
};