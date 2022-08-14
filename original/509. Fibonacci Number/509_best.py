class Solution:

    # def fib(self, n: int) -> int:
    #     if n == 0:
    #         return 0
    #     elif n == 1:
    #         return 1
    #     else:
    #         return self.fib(n-1) + self.fib(n-2)
    
    """
        Title: 509. Fibonacci Number
        Time Complexity: O(N)
        Algorithm: 
            1. DP(Bottom UP)
        
        Date: 07/14/2021 00:12	
        Time: 32 ms  -- beat 65.12%
        Memory: 14.1 MB  -- beat 69.75%
    """
    
    def fib(self, n: int) -> int:
        arr = [0, 1]
        
        if n < 2:
            return arr[n]
        else:
            i = 2
            while i <= n:
                arr.append(arr[i-1] + arr[i-2])
                i += 1
            
            return arr[n]