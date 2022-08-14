class Solution:
    """
        Title: 915. Partition Array into Disjoint Intervals
        Time Complexity: O(N)
        Algorithm: 
            1. Use a more clever approach(Only one traversal)
        
        Date: 07/22/2021 18:16					
        Time: 176 ms -- beat 92.42%
        Memory: 18.5 MB  -- beat 8.57%
    """
    def partitionDisjoint(self, nums: List[int]) -> int:
        ans = 1
        mx = nums[0]
        possible = 0
        max_of_all = mx
        
        for i in range(1, len(nums)):
            if mx > nums[i]:
                ans += (possible + 1)
                possible = 0
                mx = max_of_all
            
            else:
                possible += 1
                max_of_all = max(max_of_all, nums[i])
        
        return ans