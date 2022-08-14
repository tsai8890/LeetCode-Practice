import random

class Solution:
    """
        Title: 215. Kth Largest Element in an Array
        Time Complexity: 
            - Worst Case: O(N^2)
            - Average Case: O(N)

        Algorithm: 
            1. Divide and Conquer

        Note:
            1. The reverse version of Lomuto_partition

        Date: 07/13/2021 23:06	
        Time: 60 ms  -- beat 89.42%
        Memory: 15 MB  -- beat 74.91%
    """

    def lomuto_partition(self, nums: List[int], st: int, end: int) -> int:
        random.seed(None)
        pivot = random.randrange(st, end+1)
        nums[end], nums[pivot] = nums[pivot], nums[end]
        
        i = st - 1
        for j in range(st, end+1):
            if nums[j] >= nums[end]:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        return i
    
    def find_recursion(self, nums: List[int], st: int, end: int, k: int) -> int:
        pivot = self.lomuto_partition(nums, st, end)
        num = pivot - st + 1
        
        if num == k:
            return nums[pivot]
        
        elif num < k:
            return self.find_recursion(nums, pivot+1, end, k - num)
        
        else:
            return self.find_recursion(nums, st, pivot-1, k)  
    
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.find_recursion(nums, 0, len(nums)-1, k)