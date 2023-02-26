#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree() {
        n = 100000;
        bit = vector<int>(n+1, 0);
    }

    void addVal(int index, int val) {
        for (int i = index; i <= n; i += (i&-i)) {
            bit[i] += val;
        }
    }

    int queryRange(int index) {
        if (index == 0) {
            return 0;
        }
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
    long long n;
    vector<int> bit;
};

typedef BinaryIndexedTree BIT;

class LUPrefix {
public:
    LUPrefix(int n) {
        bit = BIT();
        this->n = n;
    }
    
    void upload(int video) {
        bit.addVal(video, 1);
    }
    
    int longest() {
        if (bit.queryRange(1) != 1) {
            return 0;
        }

        int left = 1, right = n;
        while (left < right-1) {
            int mid = (left + right) / 2;
            int queryRes = bit.queryRange(mid);
            if (queryRes != mid) {
                right = mid - 1;
            }
            else if (queryRes == mid) {
                left = mid;
            }
        }

        if (bit.queryRange(right) == right) {
            return right;
        }
        return left;
    }

private:
    BIT bit;
    int n;
    vector<bool> videos;
    int notUpload;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */