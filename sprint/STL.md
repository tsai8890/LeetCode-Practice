# C++ STL

## std::string
- 用法
    - 新增 / 刪除 (只支援從尾端)
        - push_back()
        - pop_back()
            - no return value

    - 存取
        - 可用 index 隨機存取任一字元
        - 可用 front(), back() 存取頭尾字元
            - 是回傳 reference，可以直接修改

    - 其它
        - length()
        - empty()

## std::vector
- 用法
    - 新增 / 刪除 (只支援從尾端)
        - push_back()
        - pop_back()
            - no return value

    - 存取
        - 可用 vector[index] 隨機存取任一元素
        - 可用 front(), back() 存取頭尾
            - 是回傳 reference，可以直接修改

    - 其它
        - size()
        - empty()

## std::deque
- 用法
    - 新增 / 刪除 (從前面 or 後面都可以)
        - push_front()
        - push_back()
        - pop_front()
        - pop_back()

    - 存取
        - 可用 deque[index] 隨機存取任一元素
        - front()
        - back()

    - 其它
        - size()
        - empty()

## std::queue
- 用法
    - 新增 / 刪除 (只能從前面 pop / 從後面 push)
        - push()
        - pop()

    - 存取
        - front()
        - back()

    - 其它
        - size()
        - empty()

## std::stack
- 用法
    - 新增 / 刪除 (只支援 push / pop)
        - push()
        - pop()
            - no return value

    - 存取
        - top(): 回傳 stack 頂端的元素的 reference

    - 其它
        - size()
        - empty()

## std::pair
- 宣告方法
```C++=
pair<T1, T2> p;
```

- 用法
    - member variables
        - pair.first: 回傳第一個元素
        - pair.second: 回傳第二個元素

## std::unordered_map
- 宣告方法
```C++=
unordered_map<KEY_T, VALUE_T> uMap; 
```

- 用法
    - 查找
        - find(KEY_T key)
            - 找到就回傳該位置的 iterator
            - 找不到回傳 uMap.end()

    
    - 遍歷
        - 使用 pair 遍歷
        ```C++=
            // Basic
            // Note: 不可以加 "&"，會出錯
            for (pair<KEY_T, VALUE_T> e: uMap) {
                cout << e.first;  // Key
                cout << e.second; // Value
            }
            
            // Lazy
            // Note: 不可以加 "&"，會出錯
            for (auto e: uMap) {
                cout << e.first;  // Key
                cout << e.second; // Value
            }
        ``` 

        - 使用 iterator 遍歷
        ```C++=
            // Basic - forLoop
            unordered_map<KEY_T< VALUE_T>>::iterator it;
            // 其實 "*it" 就是 pair<KEY_T, VALUE_T>

            for (it = uMap.begin(); it != uMap.end(); it ++) {
                cout << it->first; // Key
                cout << it->second; // Value
            }

            // Basic - whileLoop
            unordered_map<KEY_T< VALUE_T>>::iterator it;
            it = uMap.begin();
            while (it != uMap.end()) {
                cout << it->first; // Key
                cout << it->second; // Value
                it ++;
            }
        ``` 

## std::priority_queue
- 引入函式庫
```
#include <queue>
// 沒有 <priority_queue>
```

- 宣告方法
```C++=
// Most Important
// C++ 的 priority queue 比較函數定義是反過來的

// Min-Heap
priority_queue<T, vector<T>, greater<T>> pq; 

// Max-Heap
priority_queue<T, vector<T>, less<T>> pq; 

// 客製化比較函式
class Compare {
public:
    bool operator() (const T& t1, const T& t2) {
        return t1.val < t2.val;
    }
}
priority_queue<T, vector<T>, Compare> pq; 
```

- 用法
    - 新增 / 刪除
        - push()
        - pop()
    
    - 存取
        - top()
    
    - 其它
        - size()
        - empty()