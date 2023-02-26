#include <vector>
using namespace std;

#define ll long long

// Segment Tree + lazy tag

struct Node {
    int l, r;
    int v, tag;
    
    Node(int l, int r, int v) {
        this->l = l;
        this->r = r;
        this->v = v;
        this->tag = 0;
    }
    Node() {}

    int rv() {
        return (tag == 1) ? r-l+1-v : v;
    }
};

struct SegmentTree {
    Node nodes[400000];

    SegmentTree(vector<int>& nums) {
        build(nums, 0, 0, nums.size()-1);
    }

    void build(vector<int>& nums, int i, int l, int r) {
        if (l == r) nodes[i] = Node(l, r, (nums[l] == 1) ? 1 : 0);
        else {
            int mid = (l + r) / 2;
            build(nums, i*2+1, l, mid);
            build(nums, i*2+2, mid+1, r);
            nodes[i] = Node(l, r, nodes[i*2+1].v + nodes[i*2+2].v);
        }
    }

    void push(int i) {
        if (nodes[i].tag == 1) {
            nodes[i].v = nodes[i].rv();
            nodes[i*2+1].tag = (nodes[i*2+1].tag == 1) ? 0 : 1;
            nodes[i*2+2].tag = (nodes[i*2+2].tag == 1) ? 0 : 1;
            nodes[i].tag = 0;
        }
    }

    void update(int i, int l, int r) {
        if (nodes[i].l == l && nodes[i].r == r) {
            nodes[i].tag = (nodes[i].tag == 1) ? 0 : 1;
            return;
        }

        int mid = (nodes[i].l + nodes[i].r) / 2;
        if (r <= mid) update(i*2+1, l, r);
        else if (l > mid) update(i*2+2, l, r);
        else {
            update(i*2+1, l, mid);
            update(i*2+2, mid+1, r);
        }
        nodes[i].v = nodes[i*2+1].rv() + nodes[i*2+2].rv();
    }

    ll query(int i, int l, int r) {
        if (nodes[i].l == l && nodes[i].r == r) {
            return nodes[i].rv();
        }

        push(i);
        int mid = (nodes[i].l + nodes[i].r) / 2;
        if (r <= mid) return query(i*2+1, l, r);
        else if (l > mid) return query(i*2+2, l, r);
        else {
            return query(i*2+1, l, mid) + query(i*2+2, mid+1, r);
        }
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        SegmentTree sgt(nums1);
        
        ll sum_2 = 0;
        for (auto num: nums2) {
            sum_2 += num;
        }
        
        vector<ll> res;
        for (int i = 0; i < queries.size(); i ++) {
            if (queries[i][0] == 1) {
                sgt.update(0, queries[i][1], queries[i][2]);
            }
            else if (queries[i][0] == 2) {
                sum_2 += sgt.query(0, 0, nums1.size()-1) * queries[i][1];
            }
            else {
                res.push_back(sum_2);
            }
        }
        return res;
    }
};