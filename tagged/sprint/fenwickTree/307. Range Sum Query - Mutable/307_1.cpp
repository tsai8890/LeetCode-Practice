#include <vector>
using namespace std;

/*
    Binary Indexed Tree (BIT) a.k.a. 「樹狀數組」
    Time Complexity
        - query: O(logN)
        - update: O(logN)
*/

class BinaryIndexedTree {
public:
    BinaryIndexedTree(vector<int> nums) {
        this->n = nums.size();
        this->bit = vector<int>(n+1, 0);
        for (int i = 0; i < n; i ++) {
            update(i+1, nums[i]);
        }
    }

    BinaryIndexedTree() {}

    void update(int index, int add) {
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] += add;
        }
    }

    int query(int index) {
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

class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->BIT = BinaryIndexedTree(nums);
    }
    
    void update(int index, int val) {
        BIT.update(index+1, val-nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return BIT.query(right+1) - BIT.query(left);
    }

private:
    vector<int> nums;
    BinaryIndexedTree BIT;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */