class Solution:
    """
        Title: 240. Search a 2D Matrix II
        Time Complexity: O(MlogN)
        Algorithm: 
            1. Binary searching each row
        
        Date: 07/22/2021 19:18							
        Time: 160 ms -- beat 84.70%
        Memory: 20.7 MB  -- beat 36.22%
    """
    def searchMatrix(self, matrix, target):
        def b_search(nums):
            i, j = 0, len(nums)-1
            while i <= j:
                if i == j:
                    return nums[i] == target
                else:
                    mid = (i + j) // 2
                    if target < nums[mid]:
                        j = mid - 1

                    elif target > nums[mid]:
                        i = mid + 1
                    
                    else:
                        return True
            return False
        
        for row in range(len(matrix)):
            if b_search(matrix[row]):
                return True
        return False