class Solution:
    """
        Title: Two Sum
        Time Complexity: O(N)
        Algorithm: 
            1. Python dict() to implement hash table

        Date: 2021.7.11 18:30
        Time: 60 ms  -- beat 70.15%
        Memory: 15.3 MB  -- beat 37.52%
    """

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_T = dict()
        for i in range(len(nums)):
            n = target - nums[i]
            if n in hash_T:
                return [hash_T[n], i]

            hash_T[nums[i]] = i