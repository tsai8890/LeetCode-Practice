# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 814. Binary Tree Pruning
        Time Complexity: 
            - O(N)

        Algorithm: 
            1. Divide and Conquer

        Date: 07/24/2021 11:39		
        Time: 20 ms  -- beat 99.01%
        Memory: 13.9 MB  -- beat 99.88%
    """
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        
        if root.val or root.left or root.right:
            return root
        else:
            return None
        