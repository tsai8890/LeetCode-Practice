class Solution:
    """
        Title: 18. 4Sum
        Time Complexity: O(N^3)
        Algorithm: 
            1. 3Sum Skills(Two Pointers)
        
        Date: 07/17/2021 13:13	
        Time: 740 ms  -- beat 60.81%
        Memory: 14.2 MB  -- beat 78.34%
    """

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for x in range(len(nums)-3):
            if x != 0 and nums[x] == nums[x-1]:
                continue
                
            for y in range(x+1, len(nums)-2):
                if y != x+1 and nums[y] == nums[y-1]:
                    continue
                    
                cur_target = target - nums[x] - nums[y]
                
                i = y + 1
                j = len(nums) - 1
                
                while i < j:
                    sum_ = nums[i] + nums[j]
                    
                    if sum_ > cur_target:
                        j -= 1
                        
                    elif sum_ < cur_target:
                        i += 1
                        
                    else:
                        res.append([nums[x], nums[y], nums[i], nums[j]])
                        i += 1
                        while i < j and nums[i-1] == nums[i]:
                            i += 1
                            
                        j -= 1
                        while i < j and nums[j] == nums[j+1]:
                            j -= 1
                
        return res
                