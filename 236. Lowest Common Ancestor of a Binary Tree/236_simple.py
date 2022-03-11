# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    """
        Title: 236. Lowest Common Ancestor of a Binary Tree
        Time Complexity: 
            - O(N)

        Algorithm: 
            1. DFS
            2. LCA(root):
                - case 1: if there is a LCA in the subtree, return LCA
                - case 2: if no LCA, only p or q in the subtree, return p or q
                - case 3: No LCA or p or q in the subtree, return None

        Date: 07/15/2021 18:31		
        Time: 68 ms  -- beat 84.84%
        Memory: 25.3 MB  -- beat 58.17%
    """
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None:
            return root
        
        if root == p or root == q:
            return root
        
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        
        if left and right:
            return root

        elif left:
            return left
        
        else:
            return right