class Solution:
    """
        Title: 611. Valid Triangle Number
        Time Complexity: O(N^2)
        Algorithm: 
            1. 3Sum Skills(Two Pointers)
        
        Date: 07/16/2021 00:15	
        Time: 1176 ms  -- beat 57.26%
        Memory: 14.3 MB  -- beat 84.62%
    """
    
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        count = 0
        
        print(nums)
        for x in range(len(nums)-2):    
            
            i, j = x+1, len(nums)-1
            while i < j:
                sum_ = nums[i] + nums[j]
                
                if sum_ <= nums[x]:
                    j -= 1
                
                else:
                    # for k in range(i+1, j+1):
                    #     print(nums[x], nums[i], nums[k])
                    count += (j - i)
                    i += 1
        
        return count