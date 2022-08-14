# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
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

            2. O(N)-time to convert linked-list to array

        Date: 07/17/2021 01:10		
        Time: 120 ms  -- beat 95.24%
        Memory: 20.1 MB  -- beat 59.14%
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
    
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        self.nums = []
        while head != None:
            self.nums.append(head.val)
            head = head.next

        if self.nums == []:
            return None
        else:
            return self.dfs(0, len(self.nums)-1)