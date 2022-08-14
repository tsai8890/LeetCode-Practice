class Solution:
    """
        Title: 915. Partition Array into Disjoint Intervals
        Time Complexity: O(N)
        Algorithm: 
            1. Brutally check the partition point
            2. Use min_ and max_ to pre-compute the information needed
        
        Date: 07/22/2021 16:29				
        Time: 212 ms -- beat 44.66%
        Memory: 18.4 MB  -- beat 31.18%
    """
    def partitionDisjoint(self, nums: List[int]) -> int:        
        max_ = [nums[0]]
        for i in range(1, len(nums)):
            max_.append(max(max_[-1], nums[i]))
        
        min_ = [nums[-1]]
        for i in range(len(nums)-2, -1, -1):
            min_.append(min(min_[-1], nums[i]))
        
        min_ = min_[::-1]

        for j in range(0, len(nums)-1):
            if max_[j] <= min_[j+1]:
                break
        return j + 1