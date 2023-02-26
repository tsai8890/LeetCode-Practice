#include <vector>
#include <unordered_map>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(vector<int>& nums) {
        n = nums.size();
        bit = vector<int>(n+1, 0);
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
    long long n;
    vector<int> bit;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        unordered_map<int, bool> numSet;
        for (int i = 0; i < nums.size(); i ++) {
            if (numSet.find(nums[i]) == numSet.end()) {
                numSet[nums[i]] = true;
            }
        }

        vector<int> keys;
        for (auto p: numSet) {
            keys.push_back(p.first);
        }
        sort(keys.begin(), keys.end());

        int total = 0;
        BinaryIndexedTree bit(nums);
        for (int j = 0; j < nums.size(); j ++) {
            total += j - query(bit, keys, 2*(long long)(nums[j]), j);
            update(bit, keys, nums[j]);  
        }
        return total;
    }

    void update(BIT& bit, vector<int>& keys, int num) {
        int left = 0, right = keys.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (keys[mid] > num) {
                right = mid - 1;
            }   
            else if (keys[mid] < num) {
                left = mid + 1;
            }    
            else {
                left = mid;
                right = mid;
            }
        }
        bit.addVal(left+1, 1);
    }

    int query(BIT& bit, vector<int>& keys, long long num, int total) {
        if (num >= keys.back()) {
            return total;
        }
        if (num < keys.front()) {
            return 0;
        }

        int left = 0, right = keys.size()-1;
        while (left < right - 1) {
            int mid = (left + right) / 2;
            if (keys[mid] > num) {
                right = mid;
            }   
            else if (keys[mid] < num) {
                left = mid;
            }    
            else {
                left = mid;
                right = mid + 1;
            }
        }

        if (keys[right] == num) {
            return bit.queryRange(right+1);
        }
        else {
            return bit.queryRange(left+1);
        }
    }
};