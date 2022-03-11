# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 889. Construct Binary Tree from Preorder and Postorder Traversal
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
        
        Date: 07/17/2021 14:19		
        Time: 48 ms -- beat 90.28%
        Memory: 14.3 MB  -- beat 35.87%
    """
    def build(self, pos_i, pre_i, pre_j) -> TreeNode:
        if pre_i == pre_j:
            return TreeNode(self.pre[pre_i])
        
        root = TreeNode(self.post[pos_i])
        mid = self.table[self.post[pos_i-1]]
        
        if mid <= pre_j:
            root.right = self.build(pos_i-1, mid, pre_j)
            pos_i -= (pre_j - mid + 1)
            
        if pre_i < mid - 1:
            root.left = self.build(pos_i-1, pre_i+1, mid-1)
            
        return root
    
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        self.pre = pre
        self.post = post
        self.table = {}
        
        for i, num in enumerate(self.pre):
            self.table[num] = i
        
        return self.build(len(self.post)-1, 0, len(self.pre)-1)