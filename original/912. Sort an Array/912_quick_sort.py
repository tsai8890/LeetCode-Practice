import random

class Solution:
    def Lomuto_partition(self, nums: List[int], st: int, end: int) -> int:
        random.seed(None)
        pivot = random.randrange(st, end+1)
        nums[pivot], nums[end] = nums[end], nums[pivot]
        
        i = st - 1
        for j in range(st, end+1):
            if nums[j] <= nums[end]:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]        
        return i
        
        
    def quick_sort(self, nums: List[int], st: int, end: int) -> None:
        if st == end:
            return
        
        else: 
            pivot = self.Lomuto_partition(nums, st, end)
            if st + 1 < pivot: 
                self.quick_sort(nums, st, pivot-1)

            if pivot + 1 < end :
                self.quick_sort(nums, pivot+1, end)
        
        
    def sortArray(self, nums: List[int]) -> List[int]:
        """
        Quick Sort using Lomuto Partition
        """
        self.quick_sort(nums, 0, len(nums)-1)
        return nums
