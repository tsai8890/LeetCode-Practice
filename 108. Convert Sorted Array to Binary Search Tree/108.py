# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 108. Convert Sorted Array to Binary Search Tree
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
        
        Note: 
            1. If the size of the left subtree and that of the right subtree
               are the same or at most different by one, for every node, then
               it's a perfect binary search tree(for the h-1 levels), also a 
               height-balanced BST
        
        Date: 07/17/2021 00:39		
        Time: 52 ms  -- beat 97.01%
        Memory: 15.7 MB  -- beat 17.24%
    """

    def dfs(self, i, j) -> TreeNode:
        if i == j:
            return TreeNode(self.nums[i])
        
        mid = (i + j) // 2
        root = TreeNode(self.nums[mid])
        
        if i < mid:
            root.left = self.dfs(i, mid-1)
        
        if mid < j:
            root.right = self.dfs(mid+1, j)
        
        return root
    
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        self.nums = nums
        return self.dfs(0, len(nums)-1)