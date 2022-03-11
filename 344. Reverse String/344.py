class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        """
        Title: 344. Reverse String
        Time Complexity: 
            - O(N)

        Algorithm: 
            1. Recursion

        Note:
            1. s[::-1] will copy a new list instance, 
               which is not in-place

        Date: 07/15/2021 18:44		
        Time: 192 ms  -- beat 87.99%
        Memory: 18.3 MB  -- beat 94.65%
        """

        i, j = 0, len(s)-1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i += 1
            j -= 1