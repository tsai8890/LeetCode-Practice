# Binary Indexed Tree (a.k.a. BIT, Fenwick Tree)
## Feature
- 支援 O(logN) 的單點更新
- 支援 O(logN) 的前綴和查詢

## Tutorial
1.  [Intuitive tutorial](https://www.youtube.com/watch?v=WbafSgetDDk) 
2.  [Detailed Definition](https://hackmd.io/@wiwiho/CPN-binary-indexed-tree)

## 常見題型


## Template
```C++
class BinaryIndexedTree {
public:
    BinaryIndexedTree(vector<int> nums) {
        this->n = nums.size();
        this->bit = vector<int>(n+1, 0);
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

typedef BinaryIndexedTree BIT;
```
