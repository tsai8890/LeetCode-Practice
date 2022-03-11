class Solution:
    """
        Title: 324. Wiggle Sort II
        Time Complexity: O(NlogN)
        Algorithm: 
            1. Sort
        
        Note:
            1. It can be proved that the solution is right.
            2. Proof URL: https://www.bilibili.com/video/BV1pE411X7kC/
            3. More elegant: 
               - It use 座標映射, which nums[i] -> temp[(i*2+1) % (n|1)],
                 when we sort the array in the descending order

        Date: 07/22/2021 23:53								
        Time: 156 ms -- beat 95.84%
        Memory: 17.1 MB  -- beat 72.00%
    """
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        if nums == None:
            return 
        
        temp = sorted(nums.copy(), reverse=True)
        n = len(temp)
        for i in range(n):
            nums[(i*2+1)%(n|1)] = temp[i]