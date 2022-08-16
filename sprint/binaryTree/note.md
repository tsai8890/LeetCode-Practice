[Binary Tree]

## 思考模式
- Traversal
    - 有三種 traversal 的規則
        - preOrder
            - LC 144.
        - inOrder
            - LC 94.
        - postOrder
            - LC 145.
    
    - 有兩種實現方式
        1. Recursion
            - 簡單的啦
               
        2. Iteration 
            - 可以使用 stack 完全模擬 recursion, everytime
            - 有兩種版本 
                i. method 1 
                    - 完全按照 recursion 的邏輯 (Recommended)
                    - 很好寫，也很好理解
                    - 三種 traversal 的 code 都差不多
                    - 需要標記每個 node 的狀態
                        - 狀態: expanded / not expanded
                        - 可以利用空指標法來標記
                            - 在 node 後面再加一個 null 的 node，代表 expanded
                            - node 後面沒有 null node，代表 not expanded

                ii. method 2
                    - 對每一種 traversal 都進行特別處理
                    - 比較難理解 & 也比較難實作
                        - 尤其是 inOrder :P
                    - 每一種 traversal 都長得不太一樣
     
- 必須練習的
    - Binary Tree 有關的題目，都要用 BFS & DFS 想過一遍

- 經典題型
- Traversal 
    - LC 144. Binary Tree Preorder Traversal
    - LC 94. Binary Tree Inorder Traversal
    - LC 145. Binary Tree Postorder Traversal

- Level Order Traversal
    - LC 102. Binary Tree Level Order Traversal
    - LC 107. Binary Tree Level Order Traversal II
    - LC 429. N-ary Tree Level Order Traversal
    - LC 515. Find Largest Value in Each Tree Row
    - LC 637. Average of Levels in Binary Tree
    - LC 199. Binary Tree Right Side View
    - LC 116. Populating Next Right Pointers in Each Node
    - LC 117. Populating Next Right Pointers in Each Node II
 
- Invert (DFS or BFS 都可)
    - LC 226. Invert Binary Tree

- 深度、Node 數量 (DFS or BFS 都可)
    - LC 104. Maximum Depth of Binary Tree
    - LC 111. Minimum Depth of Binary Tree
    
- Symmetry (DFS or BFS 都可，DFS 較好寫)
    - LC 101. Symmetric Tree
    - LC 100. Same Tree
    - LC 572. Subtree of Another Tree

- 總和
    - LC 404. Sum of Left Leaves
    - LC 112. Path Sum
    - LC 113. Path Sum II

- 路徑
    - LC 257. Binary Tree Paths

- 搜尋元素 (DFS or BFS)
    - LC 513. Find Bottom Left Tree Value
     
- 重建 binary tree (Divide & Conquer)
    - LC 106. Construct Binary Tree from Inorder and Postorder Traversal
    - LC 654. Maximum Binary Tree
    - LC 617. Merge Two Binary Trees
        - 想法和「LC 100. Same Tree」幾乎一樣

- Others (But important!!!)
    - LC 110. Balanced Binary Tree
    - LC 222. Count Complete Tree Nodes
