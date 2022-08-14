class Solution:
    """
        Title: 240. Search a 2D Matrix II
        Time Complexity: O(M+N)
        Algorithm: 
            1. Divide and Conquer
        
        Note:
            1. Starting from the left bottom corner, 
               and let the point move upward or rightward
               , like a snake.
        
        Date: 07/22/2021 19:07						
        Time: 148 ms -- beat 99.51%
        Memory: 20.7 MB  -- beat 26.22%
    """
    def searchMatrix(self, matrix, target):
        row, col = len(matrix)-1, 0
        
        while True:
            if row < 0 or col >= len(matrix[0]):
                return False
            
            if target < matrix[row][col]:
                row -= 1
                
            elif target > matrix[row][col]:
                col += 1
            
            else:
                return True