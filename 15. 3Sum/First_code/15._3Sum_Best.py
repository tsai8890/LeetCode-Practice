class Solution:
    """
        Title: 3Sum
        Time Complexity: O(N^2)
        Algorithm: 
            1. 2Sum skills(Two pointers)
            2. Pruning
                i. Remove positive beginnings
                ii. Remove duplicated beginings
        
        Date: 2021.7.11 17:00
        Time: 680 ms  -- beat 92.91%
        Memory: 17.5 MB  -- beat 73.20%
    """
    
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = set()
        nums.sort()
        
        len_ = len(nums)
        
        for i in range(len_-2):

            """ ------- Pruning ------- """
            if nums[i] > 0:
                break
            
            if i > 0 and nums[i-1] == nums[i]:
                continue
            """ ------- Pruning ------- """    
            
            l = i + 1
            r = len_ - 1
            
            while l < r:
                sum_ = nums[i] + nums[l] + nums[r]
                
                if sum_ > 0:
                    r -= 1

                elif sum_ < 0:
                    l += 1

                else:
                    res.add((nums[i], nums[l], nums[r]))
                    l += 1
                    r -= 1

                    """ ------- Pruning ------- """  
                    while l <= r and nums[l-1] == nums[l]:
                        l += 1
                    
                    while r >= l and nums[r] == nums[r+1]:
                        r -= 1
                    """ ------- Pruning ------- """  
        return res