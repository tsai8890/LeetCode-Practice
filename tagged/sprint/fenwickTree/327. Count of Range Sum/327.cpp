#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long

class BinaryIndexedTree {
public:
    BinaryIndexedTree(vector<ll>& nums) {
        n = nums.size();
        bit = vector<ll>(n+1, 0);
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
    ll n;
    vector<ll> bit;
};

typedef BinaryIndexedTree BIT;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<ll> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i ++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        unordered_map<ll, bool> numSet;
        for (int i = 0; i < n; i ++) {
            if (numSet.find(prefSum[i]) == numSet.end()) {
                numSet[prefSum[i]] = true;
            }
        }

        vector<ll> prefKeys;
        for (auto p: numSet) {
            prefKeys.push_back(p.first);
        }
        sort(prefKeys.begin(), prefKeys.end());

        BIT bit(prefKeys);
        int total = 0;
        for (int i = 0; i < prefSum.size(); i ++) {
            if (lower <= prefSum[i] && prefSum[i] <= upper) {
                total ++;
            }
            total += query(bit, prefKeys, prefSum[i]-(ll)lower, i);
            total -= query(bit, prefKeys, prefSum[i]-(ll)upper-1, i);
            update(bit, prefKeys, prefSum[i]);
        }
        return total;
    }

    void update(BIT& bit, vector<ll>& keys, ll num) {
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
                break;
            }
        }
        bit.addVal(left+1, 1);
    }

    int query(BIT& bit, vector<ll>& keys, ll num, int total) {
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