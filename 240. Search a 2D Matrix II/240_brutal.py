class Solution:
    """
        Title: 240. Search a 2D Matrix II
        Time Complexity: O(M*N)
        Algorithm: 
            1. Brutally search the whole matrix
        
        Date: 07/22/2021 18:48						
        Time: 168 ms -- beat 53.64%
        Memory: 20.6 MB  -- beat 36.22%
    """
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == target:
                    return True
        return False