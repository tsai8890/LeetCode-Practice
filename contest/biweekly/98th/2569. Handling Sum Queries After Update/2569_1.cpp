#include <vector>
#include <cmath>
using namespace std;

#define ll long long

// Sqrt Decomposition + lazy tag

struct Block {
    int ones, total;
    int left, right;
    int tag;

    Block() {
        
    }
    
    Block(vector<int>& nums, int l, int r) {
        ones = 0;
        for (int i = l; i <= r; i ++) {
            if (nums[i] == 1) {
                ones ++;
            }
        }
        tag = 0;
        total = r-l+1;            
        left = l;
        right = r;
    }
    
    void pushDown(vector<int>& nums) {
        if (tag == 1) {
            for (int i = left; i <= right; i ++) {
                nums[i] = (nums[i] == 0) ? 1 : 0;
            }
            ones = total - ones;
            tag = 0;
        }
    }

    int getOnes(vector<int>& nums, int l, int r) {
        if (l == left && r == right) {
            return (tag == 1) ? total - ones : ones;
        }
        pushDown(nums);
        return ones;
    }

    void flip(vector<int>& nums, int l, int r) {
        if (l == left && r == right) {
            tag = (tag == 0) ? 1 : 0;
            return;
        }

        pushDown(nums);
        for (int i = left; i <= right; i ++) {
            if (l <= i && i <= r) {
                nums[i] = (nums[i] == 0) ? 1 : 0;
                ones += (nums[i] == 0) ? -1 : 1;
            }
        }
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int N = nums1.size();
        int G = (int)(sqrt(N));
        int NG = (N % G == 0) ? N/G : (N/G)+1;
        
        vector<Block> blocks;
        for (int i = 0; i < NG; i ++) {
            blocks.push_back(Block(nums1, i*G, min((i+1)*G-1, N-1)));
        }
        
        ll sum_2 = 0;
        for (auto num: nums2) {
            sum_2 += num;
        }
        
        vector<ll> res;
        for (int i = 0; i < queries.size(); i ++) {
            if (queries[i][0] == 1) {
                int l = queries[i][1];
                int r = queries[i][2];
                int lG = (l/G);
                int rG = (r/G);
                
                if (lG == rG) {
                    blocks[lG].flip(nums1, l, r);
                }
                else {
                    for (int g = lG+1; g <= rG-1; g ++) {
                        blocks[g].flip(nums1, blocks[g].left, blocks[g].right);
                    }
                    blocks[lG].flip(nums1, l, blocks[lG].right);
                    blocks[rG].flip(nums1, blocks[rG].left, r);
                }
            }
            else if (queries[i][0] == 2) {
                ll sum_1 = 0;
                for (int i = 0; i < NG; i ++) {
                    sum_1 += blocks[i].getOnes(nums1, blocks[i].left, blocks[i].right);
                }
                sum_2 += sum_1 * queries[i][1];
            }
            else {
                res.push_back(sum_2);
            }
        }
        return res;
    }
};