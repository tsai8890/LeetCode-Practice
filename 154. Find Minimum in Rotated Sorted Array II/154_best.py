class Solution:
    """
        Title: Find Minimum in Rotated Sorted Array II
        Time Complexity: O(log(N-k) + k)
        Algorithm: 
            1. Divide and conquer
            2. First remove the last k elements which equal to 
               the first element of the sequence

        Date: 2021.7.12 20:45
        Time: 48 ms  -- beat 90.15%
        Memory: 15 MB  -- beat 12.44%
    """

    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        
        while l < r and nums[r] == nums[0]:
            r -= 1
        
        while l < r:
            mid = (l + r) // 2
            if nums[mid] >= nums[0]:
                l = mid + 1
            else:
                r = mid
        
        return nums[0] if nums[0] < nums[l] else nums[l]
        