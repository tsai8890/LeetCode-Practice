class Solution:
    """
        Title: 324. Wiggle Sort II
        Time Complexity: O(NlogN)
        Algorithm: 
            1. Sort
        
        Note:
            1. It can be proved that the solution is right.
            2. Proof URL: https://www.bilibili.com/video/BV1pE411X7kC/
        
        Date: 07/22/2021 23:22							
        Time: 164 ms -- beat 80.68%
        Memory: 17 MB  -- beat 72.00%
    """
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        if nums == None:
            return 
        
        temp = sorted(nums.copy())
        
        if len(nums) % 2 == 0:
            i, j = len(temp) // 2 - 1, len(temp) - 1
            for k in range(0, len(temp), 2):
                nums[k] = temp[i]
                nums[k+1] = temp[j]
                i, j = i-1, j-1
        
        else:
            i, j = len(temp) // 2, len(temp) - 1
            for k in range(0, len(temp)-1, 2):
                nums[k] = temp[i]
                nums[k+1] = temp[j]
                i, j = i-1, j-1
            nums[-1] = temp[0]