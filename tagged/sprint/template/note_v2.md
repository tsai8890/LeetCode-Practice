# LC 130. Surrounded Regions
> tags:  [DFS] [Graph] [UnionFind]

## Summary 
1. 這種 graph 的題目，使用 dfs 會比 disjoint set 還好寫很多...
2. 要小心這種寫法 (在 DFS 的寫法裡大量出現)
    i.  a && b: 如果 a 已經是 false，就不會執行到 b
    ii. a || b: 如果 a 已經是 true，就不會值行到 b
    比較保險的寫法是將「一定要執行到的 function」寫在 a 的位置
3. 這題是 LC 1254 的變形。

<br>

## Solutions
### Solution #1
#### Techniques
- Union Find (Disjoint Set)

#### Resource Analysis
- Time: O(N^2)
- Space: O(N^2)

#### Note
```
1. disjoint set 裡需要存「是否包含 edge/corner block」的 bool value
2. 先 traverse 一次，建立 disjoint set 後，再 traverse 一次來確認哪些要翻轉
```


### Solution #2
#### Techniques
- DFS

#### Resource Analysis
- Time: O(N^2)
- Space: O(1)

#### Note
```
1. 不需要使用額外的 visited vector，直接將原本的位置從1 翻轉成 0，就可以表示拜訪過的狀態
```


### Solution #3
#### Techniques
- DFS

#### Resource Analysis
- Time: O(N^2)
- Space: O(1)

#### Note
```
1. 只 DFS 邊緣的地方，這樣最後沒被 traverse 到的地方就是 surrounded regions
2. 寫起來更簡潔，推薦這種寫法
```

