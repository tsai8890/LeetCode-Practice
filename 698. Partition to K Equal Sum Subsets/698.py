class Solution:
    """
        Title: 698. Partition to K Equal Sum Subsets
        Time Complexity: O(K^N)
        Algorithm: 
            1. Divide & Conquer
            2. Pruning
        
        Date: 07/16/2021 13:20	
        Time: 28 ms  -- beat 99.72%
        Memory: 14.1 MB  -- beat 98.28%
    """
    def dfs(self, cur, nums, k, targets) -> bool:
        if cur == len(nums):
            return True
        
        for i in range(k):
            if nums[cur] == targets[i] or targets[i] - nums[cur] >= nums[-1]:
                targets[i] -= nums[cur]
                if self.dfs(cur+1, nums, k, targets):
                    return True
                targets[i] += nums[cur]
        return False
                
    def canPartitionKSubsets(self, nums: list[int], k: int) -> bool:
        nums.sort(reverse=True)
        sum_ = sum(nums)
        if sum_ % k != 0:
            return False
        
        target = sum_ // k
        if nums[0] > target:
            return False
        
        targets = [target] * k
        return self.dfs(0, nums, k, targets)
