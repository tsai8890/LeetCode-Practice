# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 1382. Balance a Binary Search Tree
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
        
        Note:
            1. Same technique as LeetCode Problem 108. 
        
        Date: 07/17/2021 14:59			
        Time: 328 ms -- beat 85.34%
        Memory: 20.7 MB  -- beat 51.19%
    """
    def inorder(self, root: TreeNode, ans: List[int]) -> None:
        if root == None:
            return
        
        else:
            if root.left:
                self.inorder(root.left, ans)
            ans.append(root.val)
            if root.right:
                self.inorder(root.right, ans)
                
            return
    
    def build(self, i, j) -> TreeNode:
        if i == j:
            return TreeNode(self.nums[i])
       
        else:
            mid = (i + j) // 2
            root = TreeNode(self.nums[mid])
            
            if i < mid:
                root.left = self.build(i, mid-1)
            
            if mid < j:
                root.right = self.build(mid+1, j)
            
            return root
    
    def balanceBST(self, root: TreeNode) -> TreeNode:
        ans = []
        self.inorder(root, ans)
        self.nums = ans
        
        return self.build(0, len(self.nums)-1)
        
        