class Solution:
    """
        Title: Two Sum II
        Time Complexity: O(N)
        Algorithm: 
            1. Two-Pointer skill -- O(N)
        
        Date: 2021.7.11 18:40
        Time: 64 ms  -- beat 64.70%
        Memory: 14.6 MB  -- beat 61.48%
    """
    
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers)-1
        
        while l < r:
            sum_ = numbers[l] + numbers[r]
            
            if sum_ > target:
                r -= 1
                while l < r and numbers[r] == numbers[r+1]:
                    r -= 1
            
            elif sum_ < target:
                l += 1
                while l < r and numbers[l] == numbers[l-1]:
                    l += 1
            
            else:
                return [l+1, r+1]