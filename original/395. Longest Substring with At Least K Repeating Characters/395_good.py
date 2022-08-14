class Solution:
    """
        Title: 395. Longest Substring with At Least K Repeating Characters
        Time Complexity: 
            - O(N)

        Algorithm: 
            1. Divide and Conquer

        Note:
            1. T(N) = T(N1) + T(N2) + T(N3) + ... + T(Nk) + theta(N),
               and N1 + N2 + N3 + ... + Nk < N. 
               In each layer, O(N)-time is consumed, and there are at most 
               26 layers because each layer will remove at least one character.

               So, the total time complexity = O(26*N) = O(N)
            
            2. learn to use re.split('del1 | del2 | ... | delk', str)

        Date: 07/24/2021 13:06				
        Time: 28 ms  -- beat 95.87%
        Memory: 14.4 MB  -- beat 64.88%
    """
    def longestSubstring(self, s: str, k: int) -> int:
        if k == 1:
            return len(s)
        
        if len(s) < k:
            return 0
        
        count = {}
        for i in range(len(s)):
            if s[i] not in count:
                count[s[i]] = 1
            else:
                count[s[i]] += 1
        
        filt = ''
        valid = True
        for ch in count:
            if count[ch] < k:
                filt += '|' + ch
                valid = False
        
        if valid:
            return len(s)

        import re
        filt = filt[1:]
        s_adjusted = re.split(filt, s)
        
        max_ = 0
        for s_child in s_adjusted:
            max_ = max(self.longestSubstring(s_child, k), max_)
        
        return max_