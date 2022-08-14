class Solution:
    """
        Title: 918. Maximum Sum Circular Subarray
        Time Complexity: 
            - O(N)

        Algorithm: 
            1. Dynamic Programming
        
        Note:
            1. It uses the same technique as the Maximum Subarray.
            2. If min_ == sum(nums), which means if we cut the array
               at any position, the sums of the left and right part 
               are both negative. And therefore, we only need to consider 
               the non-circular subarray(Normal subarray).
            3. Using the two lines max(max_local+nums[i], nums[i]),
               min(min_local+nums[i], nums[i]) will slower the process.

        Date: 07/24/2021 16:25				
        Time: 456 ms  -- beat 95.12%
        Memory: 18.2 MB  -- beat 98.91%
    """
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        max_local = nums[0]
        min_local = nums[0]
        max_ = max_local
        min_ = min_local
        
        for i in range(1, len(nums)):
            # min_local = min(min_local+nums[i], nums[i])
            # max_local = max(max_local+nums[i], nums[i])
            min_local = min_local + nums[i] if min_local < 0 else nums[i]
            max_local = max_local + nums[i] if max_local > 0 else nums[i]

            min_ = min(min_, min_local)
            max_ = max(max_, max_local)
            
        sum_ = sum(nums)
        if sum_ == min_:
            return max_
        else:
            return max(max_, sum_-min_)