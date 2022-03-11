class Solution:
    """
        Title: 162. Find Peak Element
        Time Complexity: O(log(N))
        Algorithm: 
            1. Divide and Conquer
        
        Date: 07/13/2021 18:39
        Time: 40 ms  -- beat 92.40%
        Memory: 14.4 MB  -- beat 42.14%
    """

    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        
        while True:
            
            if l == r:
                return l
            
            if l + 1 == r:
                if nums[l] > nums[r]:
                    return l
                else:
                    return r
                
            mid = (l + r) // 2
            
            if nums[mid-1] > nums[mid]:
                r = mid - 1
            
            elif nums[mid] < nums[mid+1]:
                l = mid + 1
            
            else:
                return mid