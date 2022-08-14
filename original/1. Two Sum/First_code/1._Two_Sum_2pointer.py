class Solution:
    """
        Title: Two Sum
        Time Complexity: O(NlogN)
        Algorithm: 
            1. Sort -- O(NlogN)
            2. Two-Pointer skill -- O(N)
        
        Date: 2021.7.11 18:20
        Time: 84 ms  -- beat 42.61%
        Memory: 14.8 MB  -- beat 83.95%
    """

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        raw = nums.copy()
        nums.sort()
        
        l, r = 0, len(nums) - 1
        
        while l < r:
            sum_ = nums[l] + nums[r]
            
            if sum_ > target:
                r -= 1
                while r > l and nums[r] == nums[r+1]:
                    r -= 1
                
            elif sum_ < target:
                l += 1
                while l < r and nums[l] == nums[l-1]:
                    l += 1
                    
            else:
                if nums[l] == nums[r]:
                    l_index = raw.index(nums[l])
                    raw.pop(l_index)
                    r_index = raw.index(nums[r]) + 1
                    
                    return [l_index, r_index]
                else:
                    return [raw.index(nums[l]), raw.index(nums[r])]
                    
        return []