# Minimum Spanning Tree
## 常見的 MST algorithm
<html>
<head>
    <style>
        table * {
            text-align: center;
        }
    </style>
</head>
<body>
    <table style="text-align: center">
        <thead>
            <tr>
                <th>演算法</th>
                <th>應用場景</th>
                <th>限制條件</th>
                <th>時間複雜度</th>
                <th>空間複雜度</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Kruskal's Algorithm</td>
                <td>找出 MST 的和 / 建構 MST</td>
                <td>無</td>
                <td>O(ElogE)</td>
                <td>O(V)</td>
            </tr>
            <tr>
                <td>Prim's Algorithm</td>
                <td>找出 MST 的和 / 建構 MST</td>
                <td>無</td>
                <td>O(ElogE)</td>
                <td>O(E)</td>
            </tr>
        </tbody>
    </table>
</body>
</html>

<br>

## MST Fundamentals - MST 演算法會用到的理論
### Cut Property
> 使用 Proof by Contradiction 可以證明

給定一個 cut(S, V-S)，在任何一個 respect 這個 cut 的 cross
中，權重最小的邊一定是 MST 的其中一個組成邊
### Cycle Property
> 使用 Proof by Contradiction 可以證明

圖上任何一個 cycle 中，權重最大的邊一定不是 MST 的組成邊

<br>

## Kruskal Algorithm
### Feature
1. 需要將邊排序
2. 使用到 disjoint set

### Steps
1. 為每個 vertex 建立一個 disjoint set
2. 將所有邊按照權重由小排到大
3. 將排序好的邊依序拿出，並合併拿出的邊的兩端點 (透過 disjoint set)
    a. 若兩端點原本就在同一個 set，代表形成 cycle，且該邊是其中權重最大的
        把該邊丟掉，它一定不是 MST 的邊
    b. 若兩端點在不同的 set，代表該邊符合 cut property
        將該邊加入 MST，更新 MST Sum

<br>

## Prim's Algorithm
### Feature
1. 使用到 min heap

### Steps
1. 建立一個空的 min heap
2. 建立一個 visited array
3. 任意選一個點當作起始點，將它的邊加入 min heap，並更新其狀態為 visited
4. 從 min heap 中拿出一個邊，加入 MST，更新 MST Sum
    > min heap 裡代表的就是一個 cross，而拿出的是 cross 裡權重最小的，符合 cut property
5. 拿出的邊所新探索的點，將它的邊(檢查不會拜訪到 visit 過的點後)加入 min heap
6. 更新新探索的點的狀態為 visited
7. 重複 4. ~ 6.，直到探索完所有點

<br>

## Reference
> [MST Fundamentals](http://alrightchiu.github.io/SecondRound/minimum-spanning-treeintrojian-jie.html)
> [MST Kruskal'ss](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
> [MST Prim's](https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/)
