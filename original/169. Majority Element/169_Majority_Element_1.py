from collections import Counter

class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        count = Counter(nums)
        for key in count:
            if count[key] > len(nums) // 2:
                return key