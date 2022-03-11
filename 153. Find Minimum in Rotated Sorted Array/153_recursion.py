class Solution:
    def recursion(self, nums, st, end):
        if st == end:
            return nums[st]
        
        else:
            mid = (st + end) // 2
            
            if nums[mid] > nums[mid+1]:
                return nums[mid+1]
            
            if nums[mid] > nums[end]:
                return self.recursion(nums, mid+1, end)
            else:
                return self.recursion(nums, st, mid)
            
    def findMin(self, nums: List[int]) -> int:
        return self.recursion(nums, 0, len(nums)-1)