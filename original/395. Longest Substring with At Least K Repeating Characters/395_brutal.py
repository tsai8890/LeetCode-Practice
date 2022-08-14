class Solution:
    """
        Title: 395. Longest Substring with At Least K Repeating Characters
        Time Complexity: 
            - O(N^2)

        Algorithm: 
            1. Brutally search

        Date: 07/24/2021 12:27			
        Time: 8192 ms  -- beat 5.06%
        Memory: 14.3 MB  -- beat 83.72%
    """
    def longestSubstring(self, s: str, k: int) -> int:
        if k > len(s):
            return 0
        
        max_len = 0
        for i in range(len(s)-(k-1)):
            count = {}
            for j in range(i, len(s)):
                if s[j] not in count:
                    count[s[j]] = 1
                else:
                    count[s[j]] += 1
                
                valid = True
                for key in count:
                    if count[key] < k:
                        valid = False
                        break
                
                if valid:
                    if j-i+1 > max_len:
                        max_len = j-i+1
        
        return max_len