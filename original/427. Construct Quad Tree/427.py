"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    """
        Title: 427. Construct Quad Tree
        Time Complexity: O(N^2)
        Proof: 
            T(N) = 4T(N/4) + N^2
            By Master Theorem, T(N) = Theta(N^2)

        Algorithm: 
            1. Divide & Conquer
        
        Note:
            1. Similar techniques to Binary Tree
        
        Date: 07/20/2021 17:24				
        Time: 112 ms -- beat 82.19%
        Memory: 15.1 MB  -- beat 60.67%
    """
    def construct(self, grid: List[List[int]]) -> 'Node':
        
        def search(left: List[int], right: List[int]) -> int:
            val = -1
            for i in range(left[0], right[0]+1):
                for j in range(left[1], right[1]+1):
                    if val == -1:
                        val = grid[i][j]
                    else:
                        if val != grid[i][j]:
                            return -1
            return val
        
        def dfs(left: List[int], right: List[int]) -> 'Node':

            if left[0] == right[0] and left[1] == right[1]:
                return Node(grid[left[0]][left[1]], 1, None, None, None, None)
            
            mid_row = (left[0] + right[0]) // 2            
            mid_col = (left[1] + right[1]) // 2
            
            pos_table = {
                0: [left, [mid_row, mid_col]], 
                1: [[left[0], mid_col+1], [mid_row, right[1]]], 
                2: [[mid_row+1, left[1]], [right[0], mid_col]],
                3: [[mid_row+1, mid_col+1], right]
            }

            res = []
            
            for i in range(4):
                left, right = pos_table[i][0], pos_table[i][1]
                res.append(search(left, right))
                
            if res[0] != -1:
                if res[0] == res[1] == res[2] == res[3]:
                    root = Node(res[0], 1, None, None, None, None)
                    return root
            
            root = Node(1, 0, None, None, None, None)
            
            for i in range(4):
                if res[i] != -1:
                    new_node = Node(res[i], True, None, None, None, None)
                else:
                    left, right = pos_table[i][0], pos_table[i][1]
                    new_node = dfs(left, right)
                    
                if i == 0:
                    root.topLeft = new_node

                elif i == 1:
                    root.topRight = new_node

                elif i == 2:
                    root.bottomLeft = new_node

                else:
                    root.bottomRight = new_node
            
            return root
        
        
        left = [0, 0]
        right = [len(grid)-1, len(grid)-1]
        return dfs(left, right)
                