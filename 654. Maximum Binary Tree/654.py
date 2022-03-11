# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 654. Maximum Binary Tree
        Time Complexity: O(N^2)
        Algorithm: 
            1. Divide & Conquer(Follow the statement, no variation)
        
        Date: 07/17/2021 14:45			
        Time: 184 ms -- beat 91.93%
        Memory: 15.2 MB  -- beat 9.75%
    """
    def dfs(self, i, j) -> TreeNode:
        if i == j:
            return TreeNode(self.nums[i])
        
        else:
            max_ = max(self.nums[i:j+1])
            mid = self.table[max_]

            root = TreeNode(max_)
            if i < mid:
                root.left = self.dfs(i, mid-1)

            if mid < j:
                root.right = self.dfs(mid+1, j)

            return root
        
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        self.nums = nums
        self.table = {}
        for i, num in enumerate(self.nums):
            self.table[num] = i
        
        return self.dfs(0, len(self.nums)-1)
        
        
    