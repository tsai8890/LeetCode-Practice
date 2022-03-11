# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    """
        Title: 24. Swap Nodes in Pairs
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
        
        Date: 07/15/2021 21:07	
        Time: 28 ms  -- beat 86.66%
        Memory: 14.2 MB  -- beat 47.81%
    """
    def swapPairs(self, head: ListNode) -> ListNode:
        
        if head == None:
            return None
        
        elif head.next == None:
            return head
        
        ret_head = ListNode()
        ret_head.next = head.next

        next_head = head.next.next
        head.next.next = head
        head.next = self.swapPairs(next_head)
        
        return ret_head.next