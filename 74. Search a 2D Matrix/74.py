class Solution:
    """
        Title: 74. Search a 2D Matrix
        Time Complexity: O(log(M*N))
        Algorithm: 
            1. Divide & Conquer(Binary Search)
        
        Note:
            1. Proof by induction
                i. When n = 1, 2, it's correct
                ii. For n >= 3, because the left part and the right part
                    both have the size in [1, n-1], and we have a correct result
                    in size in [1, n-1] by induction. As a result, we prove it.

        Date: 07/20/2021 18:27		
        Time: 36 ms -- beat 95.71%
        Memory: 14.9 MB  -- beat 32.37%
    """
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        def b_search(row: int) -> bool:
            if target < matrix[row][0] or target > matrix[row][-1]:
                return False
            
            i, j = 0, len(matrix[row])-1
            
            while i < j:
                mid = (i + j) // 2
                
                if target == matrix[row][mid]:
                    return True
                
                elif target < matrix[row][mid]:
                    j = mid - 1
                
                else:
                    i = mid + 1
                
            if i == j and target == matrix[row][i]:
                return True
            
            else:
                return False
        
        
        row_i, row_j = 0, len(matrix)-1
        
        while row_i < row_j:
            row_mid = (row_i + row_j) // 2
            
            if matrix[row_mid][0] <= target <= matrix[row_mid][-1]:
                return b_search(row_mid)
            
            elif target < matrix[row_mid][0]:
                row_j = row_mid - 1
            
            elif target > matrix[row_mid][-1]:
                row_i = row_mid + 1
                
        if row_i == row_j:
            return b_search(row_i)
        else:
            return False